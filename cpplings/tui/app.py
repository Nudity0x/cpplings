"""The ``cpplings watch`` TUI, built on Textual.

This is the primary experience: a full-screen terminal app that shows the
current exercise's check output, a progress bar, the exercise path, and a hint
on demand. A background file watcher reruns the check whenever the learner
saves the exercise, so the normal workflow is "edit in your editor, glance at
this window".

Checks run on a worker thread so the UI never freezes while the compiler runs;
an animated spinner shows progress. Solving an exercise fires a celebratory
toast, and milestones, streaks, and finished sections get their own callouts —
the goal is to make grinding through 90+ exercises feel rewarding.

Layout (top to bottom):
  * Header (app title + clock)
  * Output pane (compiler/test output — compact strip while editing)
  * Editor pane (in-place TextArea for the current exercise; hidden until `c`)
  * Tip line (rotating C++ trivia under a failing exercise)
  * Hint pane (hidden until `h`)
  * Progress bar + current exercise path
  * Prompt / status line
  * Footer (key bindings)

The inline editor is focused by default, so every action has a ctrl-combo that
fires while typing, plus a bare-letter shortcut for when the editor is closed:
  ctrl+n / n   next exercise (only once the current one is Done)
  ctrl+r / r   run/recheck the current exercise now
  ctrl+s       save the editor buffer (recheck fires automatically)
  ctrl+g / h   toggle the hint
  ctrl+b / m   toggle the section README (concept explainer)
  ctrl+l / l   toggle the exercise list (navigable: Enter jumps, x resets)
  ctrl+o / e   open the exercise in your external editor/IDE
  c            toggle the inline editor for the current exercise
  x            reset the current exercise to its original state
  ctrl+q / q   quit
  escape       close whichever overlay is open (list, then editor)
"""

from __future__ import annotations

import os
import shutil
import subprocess
import sys
from pathlib import Path
from typing import Optional

from textual import work
from textual.app import App, ComposeResult
from textual.binding import Binding
from textual.containers import Vertical
from textual.message import Message
from textual.widgets import (
    Footer,
    Header,
    Label,
    ListItem,
    ListView,
    Markdown,
    ProgressBar,
    RichLog,
    Static,
    TextArea,
)

from .. import cli
from ..app_state import AppState
from ..info_file import InfoFile
from ..runner import CheckResult, CheckStatus, check_exercise
from ..toolchain import Toolchain, ToolchainError, detect_toolchain
from ..watch import ExerciseWatcher
from . import flavor

# Frames for the "checking" spinner (Braille dots — smooth at ~12 fps).
_SPINNER_FRAMES = "⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏"


class ExerciseListItem(ListItem):
    """A single row in the exercise list, tagged with its exercise index."""

    def __init__(self, index: int, markup: str) -> None:
        super().__init__(Label(markup))
        self.exercise_index = index


class ExerciseList(ListView):
    """Navigable overlay of all exercises with done/pending markers.

    Enter (or the app's jump action) moves the watch loop to the highlighted
    exercise; ``x`` resets the highlighted exercise from the list. The app
    wires these up by reading ``highlighted_index`` / the ``Selected`` message.
    """

    BINDINGS = [
        Binding("x", "reset_highlighted", "reset", show=True),
        Binding("g,home", "goto_top", "top", show=False),
        Binding("G,end", "goto_bottom", "bottom", show=False),
    ]

    class ResetRequested(Message):
        """Posted when the user asks to reset the highlighted exercise."""

        def __init__(self, index: int) -> None:
            self.index = index
            super().__init__()

    def populate(self, state: AppState) -> None:
        """Rebuild the rows, keeping the highlight on the current exercise."""
        self.clear()
        for i, ex in enumerate(state.exercises):
            self.append(ExerciseListItem(i, self._row_markup(state, i, ex)))
        # Highlight the exercise the learner is currently on.
        self.index = state.current_ind

    @staticmethod
    def _row_markup(state: AppState, i: int, ex) -> str:
        done = state.is_done(ex.name)
        mark = "[green]✓[/green]" if done else " "
        pointer = "[b]▶[/b]" if i == state.current_ind else " "
        label = f"{ex.dir}/{ex.name}"
        if done:
            label = f"[dim]{label}[/dim]"
        return f"{pointer} [{mark}] {label}"

    def action_reset_highlighted(self) -> None:
        if self.index is not None:
            self.post_message(self.ResetRequested(self.index))

    def action_goto_top(self) -> None:
        self.index = 0

    def action_goto_bottom(self) -> None:
        if self.children:
            self.index = len(self.children) - 1


class CpplingsApp(App):
    """Textual application driving the watch loop."""

    CSS = """
    #output {
        height: auto;
        max-height: 30%;
        border: round $foreground 20%;
        padding: 0 1;
    }
    /* When the editor is open it becomes the main workspace, so the output
       pane collapses to a short scrollable strip at the top. */
    #output.compact {
        height: 6;
    }
    #code {
        display: none;
        height: 1fr;
        border: round $foreground 20%;
        padding: 0 1;
    }
    #code.visible {
        display: block;
    }
    #code:focus {
        border: round $accent;
    }
    #tip {
        display: none;
        height: auto;
        padding: 0 1;
        color: $text-muted;
        text-style: italic;
    }
    #tip.visible {
        display: block;
    }
    #hint {
        display: none;
        height: auto;
        max-height: 12;
        border: round $warning 60%;
        padding: 0 1;
        color: $warning;
    }
    #hint.visible {
        display: block;
    }
    #progress_row {
        height: auto;
        padding: 0 1;
    }
    #path {
        color: $text-muted;
        padding: 0 1;
    }
    #status {
        height: auto;
        padding: 0 1;
    }
    #output {
        border-title-color: $text-muted;
        border-title-align: left;
    }
    #code {
        border-title-color: $text-muted;
        border-title-align: left;
    }
    #exercise_list {
        display: none;
        height: 1fr;
        border: round $foreground 20%;
    }
    #exercise_list.visible {
        display: block;
    }
    #readme {
        display: none;
        height: 1fr;
        border: round $accent 60%;
        padding: 0 1;
        background: $surface;
    }
    #readme.visible {
        display: block;
    }
    """

    # Two bindings per action: a bare letter (convenient when the editor is
    # NOT focused) and a priority ctrl-combo that fires even while typing in
    # the editor. The editor is open and focused by default, so without the
    # ctrl-combos every nav key would just be inserted as text. The ctrl-combos
    # are chosen to avoid TextArea's own bindings (ctrl+a/e/d/w/x/c/v/u/k/z/y
    # and ctrl+h=backspace / ctrl+i=tab / ctrl+m=enter).
    BINDINGS = [
        Binding("n", "next", "next", show=False),
        Binding("ctrl+n", "next", "next", show=True, priority=True),
        Binding("r", "run", "recheck", show=False),
        Binding("ctrl+r", "run", "recheck", show=True, priority=True),
        Binding("ctrl+s", "save", "save", show=True, priority=True),
        Binding("h", "hint", "hint", show=False),
        Binding("ctrl+g", "hint", "hint", show=True, priority=True),
        Binding("l", "list", "list", show=False),
        Binding("ctrl+l", "list", "list", show=True, priority=True),
        Binding("m", "readme", "readme", show=False),
        Binding("ctrl+b", "readme", "readme", show=True, priority=True),
        Binding("e", "edit", "open in IDE", show=False),
        Binding("ctrl+o", "edit", "open in IDE", show=True, priority=True),
        Binding("c", "code", "toggle editor", show=False),
        Binding("x", "reset", "reset", show=False),
        Binding("q", "quit", "quit", show=False),
        Binding("ctrl+q", "quit", "quit", show=True, priority=True),
        Binding("escape", "escape", "close overlay", show=False, priority=True),
    ]

    def __init__(
        self,
        state: AppState,
        toolchain: Toolchain,
    ) -> None:
        super().__init__()
        self.state = state
        self.toolchain = toolchain
        self._watcher: Optional[ExerciseWatcher] = None
        self._hint_visible = False
        self._list_visible = False
        self._readme_visible = False
        self._code_visible = False
        self._code_dirty = False
        # Baseline text last loaded into the editor. Changed events are compared
        # against this so a programmatic load_text (which posts Changed
        # asynchronously) isn't mistaken for a user edit.
        self._code_baseline: Optional[str] = None
        # Set to "cpp" once tree-sitter C++ highlighting is registered.
        self._code_language: Optional[str] = None
        self._last_status: Optional[CheckStatus] = None
        # Entertainment state.
        self._streak = 0  # consecutive solves this session
        self._checking = False
        self._spinner_frame = 0
        self._spinner_timer = None

    # ---- layout -----------------------------------------------------------

    def compose(self) -> ComposeResult:
        yield Header(show_clock=True)
        with Vertical():
            yield RichLog(id="output", highlight=False, markup=True, wrap=True)
            yield TextArea.code_editor(
                "",
                id="code",
                show_line_numbers=True,
                soft_wrap=False,
                tab_behavior="indent",
                theme="css",
            )
            yield Static("", id="tip")
            yield Static("", id="hint")
            yield ExerciseList(id="exercise_list")
            yield Markdown("", id="readme")
            with Vertical(id="progress_row"):
                yield ProgressBar(
                    total=self.state.n_total, show_eta=False, id="progress"
                )
            yield Static("", id="path")
            yield Static("", id="status")
        yield Footer()

    def on_mount(self) -> None:
        self.title = "cpplings"
        self.sub_title = "learn C++ by fixing it"
        self.theme = "ansi-light"
        self.query_one("#output", RichLog).border_title = "program output"
        self.query_one("#code", TextArea).border_title = "editor"
        self._register_cpp_highlighting()
        self._update_progress()
        # Start the file watcher against the exercises directory.
        self._watcher = ExerciseWatcher(
            self.state.working_dir / "exercises", self._on_file_change
        )
        self._watcher.start()
        # Run the current exercise immediately so the user sees where they are.
        self._check_current()
        # Open the editor by default so the code is front and center on load.
        self.action_code()

    def on_unmount(self) -> None:
        if self._watcher is not None:
            self._watcher.stop()

    # ---- watcher callback -------------------------------------------------

    def _on_file_change(self, path: Path) -> None:
        """Called on the watcher thread; marshal back onto the app thread."""
        try:
            changed = path.resolve()
            current = self.state.exercise_path(self.state.current_exercise()).resolve()
        except OSError:
            return
        if changed == current:
            self.call_from_thread(self._check_current)

    # ---- spinner ----------------------------------------------------------

    def _start_spinner(self, name: str) -> None:
        self._checking = True
        self._spinner_frame = 0
        status = self.query_one("#status", Static)

        def tick() -> None:
            if not self._checking:
                return
            frame = _SPINNER_FRAMES[self._spinner_frame % len(_SPINNER_FRAMES)]
            self._spinner_frame += 1
            status.update(f"[cyan]{frame}[/cyan] Compiling and running {name} …")

        tick()
        self._spinner_timer = self.set_interval(1 / 12, tick)

    def _stop_spinner(self) -> None:
        self._checking = False
        if self._spinner_timer is not None:
            self._spinner_timer.stop()
            self._spinner_timer = None

    # ---- checking ---------------------------------------------------------

    def _check_current(self) -> None:
        """Kick off a check of the current exercise on a worker thread."""
        if self._checking:
            return
        ex = self.state.current_exercise()
        output_log = self.query_one("#output", RichLog)
        output_log.clear()
        output_log.write(f"[bold]Checking[/bold] {ex.dir}/{ex.name} …")
        self._hide_tip()
        self._start_spinner(f"{ex.dir}/{ex.name}")
        self._run_check(ex.name)

    @work(thread=True, exclusive=True)
    def _run_check(self, name: str) -> None:
        """Worker: compile+run off the UI thread, then hand back the result."""
        ex = self.state.current_exercise()
        result = check_exercise(
            ex, self.state.exercise_path(ex), self.toolchain, self.state.working_dir
        )
        # Marshal the UI update back onto the app thread.
        self.call_from_thread(self._on_check_done, name, result)

    def _on_check_done(self, name: str, result: CheckResult) -> None:
        self._stop_spinner()
        self._render_result(name, result)
        # Keep the inline code view in sync with what was just checked.
        self._refresh_code_if_visible()

    def _render_result(self, name: str, result: CheckResult) -> None:
        output_log = self.query_one("#output", RichLog)
        output_log.clear()

        was_done = self.state.is_done(name)
        prev_done = self.state.n_done
        self._last_status = result.status

        if result.output.strip():
            output_log.write(result.output.rstrip())

        status_line = self.query_one("#status", Static)

        if result.status is CheckStatus.DONE:
            self._hide_tip()
            self.state.mark_done_and_persist(name)
            self._update_progress()

            if not was_done:
                self._celebrate_solve(name, prev_done)

            if self.state.n_done == self.state.n_total:
                self._show_completion()
            else:
                status_line.update(
                    "[bold green]✓ Exercise done![/bold green] "
                    "Press [bold]n[/bold] for the next one."
                )
        else:
            self.state.set_pending(name)
            self._update_progress()
            # A failed attempt breaks the streak.
            if result.status in (CheckStatus.COMPILE_FAILED, CheckStatus.RUN_FAILED):
                self._streak = 0
            self._show_tip()
            if result.status is CheckStatus.NOT_DONE_MARKER:
                self._hide_tip()
                status_line.update(
                    "[yellow]✓ Compiles and passes![/yellow] "
                    'Remove the "[bold]// I AM NOT DONE[/bold]" comment to continue.'
                )
            elif result.status is CheckStatus.COMPILE_FAILED:
                status_line.update(
                    f"[red]✗ Compile error.[/red] {flavor.random_encouragement()} "
                    "([bold]h[/bold] for a hint)"
                )
            else:
                status_line.update(
                    f"[red]✗ Tests failed.[/red] {flavor.random_encouragement()} "
                    "([bold]h[/bold] for a hint)"
                )

    # ---- celebration ------------------------------------------------------

    def _celebrate_solve(self, name: str, prev_done: int) -> None:
        """Fire toasts for a fresh solve: praise, streak, section, milestone."""
        self._streak += 1

        self.notify(flavor.random_praise(), title="Solved", timeout=4)

        streak_msg = flavor.streak_message(self._streak)
        if streak_msg:
            self.notify(streak_msg, title="Streak", severity="warning", timeout=5)

        section_msg = self._section_completion_message(name)
        if section_msg:
            self.notify(section_msg, title="Section complete", timeout=6)

        milestone = flavor.milestone_message(
            prev_done, self.state.n_done, self.state.n_total
        )
        if milestone:
            self.notify(milestone, title="Milestone", severity="warning", timeout=6)

    def _section_completion_message(self, name: str) -> Optional[str]:
        """If this solve finished the exercise's whole section, return a message."""
        ex = next((e for e in self.state.exercises if e.name == name), None)
        if ex is None:
            return None
        section = ex.dir
        section_exercises = [e for e in self.state.exercises if e.dir == section]
        if all(self.state.is_done(e.name) for e in section_exercises):
            pretty = section.split("_", 1)[-1].replace("_", " ")
            return f"You cleared the whole '{pretty}' section!"
        return None

    def _show_completion(self) -> None:
        output_log = self.query_one("#output", RichLog)
        output_log.clear()
        output_log.write(f"[bold green]{flavor.COMPLETION_ART}[/bold green]")
        self.query_one("#status", Static).update(
            "[bold green]All exercises done![/bold green] "
            "You finished cpplings. Press [bold]q[/bold] to quit."
        )
        self.notify(
            "Every exercise solved. Incredible work.",
            title="🎉 cpplings complete",
            timeout=10,
        )

    # ---- tip line ---------------------------------------------------------

    def _show_tip(self) -> None:
        tip = self.query_one("#tip", Static)
        tip.update(f"💡 {flavor.random_tip()}")
        tip.add_class("visible")

    def _hide_tip(self) -> None:
        self.query_one("#tip", Static).remove_class("visible")

    def _update_progress(self) -> None:
        bar = self.query_one("#progress", ProgressBar)
        bar.update(total=self.state.n_total, progress=self.state.n_done)
        ex = self.state.current_exercise()
        path = self.state.exercise_path(ex)
        pct = int(100 * self.state.n_done / self.state.n_total) if self.state.n_total else 0
        streak = f"  •  🔥 {self._streak}" if self._streak >= 2 else ""
        self.query_one("#path", Static).update(
            f"{self.state.n_done}/{self.state.n_total} ({pct}%){streak}  •  {path}"
        )

    # ---- actions ----------------------------------------------------------

    def action_run(self) -> None:
        self._check_current()

    def action_next(self) -> None:
        if self._last_status is not CheckStatus.DONE and not self.state.is_done(
            self.state.current_exercise().name
        ):
            self.query_one("#status", Static).update(
                "[yellow]Not done yet.[/yellow] Solve this exercise before moving on."
            )
            return

        nxt = self.state.next_pending_ind()
        if nxt is None:
            self._show_completion()
            return
        self._jump_to(nxt)

    def action_hint(self) -> None:
        hint_widget = self.query_one("#hint", Static)
        if self._hint_visible:
            self._hide_hint()
            return
        ex = self.state.current_exercise()
        hint_widget.update(f"[bold]Hint[/bold]\n{ex.hint or '(no hint for this exercise)'}")
        hint_widget.add_class("visible")
        self._hint_visible = True

    def _hide_hint(self) -> None:
        self.query_one("#hint", Static).remove_class("visible")
        self._hint_visible = False

    def action_readme(self) -> None:
        """Toggle the section README (the concept explainer) for the exercise."""
        readme_widget = self.query_one("#readme", Markdown)
        if self._readme_visible:
            self._close_readme()
            return
        ex = self.state.current_exercise()
        path = self.state.working_dir / ex.readme_rel_path()
        try:
            text = path.read_text(encoding="utf-8")
        except OSError:
            pretty = ex.dir.split("_", 1)[-1].replace("_", " ")
            text = f"# {pretty}\n\n_No README for this section yet._"
        readme_widget.update(text)
        readme_widget.add_class("visible")
        self._readme_visible = True

    def _close_readme(self) -> None:
        self.query_one("#readme", Markdown).remove_class("visible")
        self._readme_visible = False
        if self._code_visible:
            self.query_one("#code", TextArea).focus()

    def action_list(self) -> None:
        lst = self.query_one("#exercise_list", ExerciseList)
        if self._list_visible:
            self._close_list()
            return
        lst.populate(self.state)
        lst.add_class("visible")
        self._list_visible = True
        lst.focus()

    def _close_list(self) -> None:
        self.query_one("#exercise_list", ExerciseList).remove_class("visible")
        self._list_visible = False
        # Return focus to the editor if it's open so typing keeps working.
        if self._code_visible:
            self.query_one("#code", TextArea).focus()

    def action_escape(self) -> None:
        """Escape closes whichever overlay is open (readme, list, then editor)."""
        if self._readme_visible:
            self._close_readme()
            return
        if self._list_visible:
            self._close_list()
            return
        if self._code_visible:
            self.action_code()

    def _jump_to(self, ind: int) -> None:
        """Move the watch loop to exercise ``ind`` and recheck it."""
        self.state.set_current(ind)
        self._hide_hint()
        self._update_progress()
        if self._code_visible:
            self._code_dirty = False
            self._render_code()
        self._check_current()

    def on_list_view_selected(self, event: ListView.Selected) -> None:
        """Enter on a list row jumps to that exercise and closes the list."""
        item = event.item
        if isinstance(item, ExerciseListItem):
            self._close_list()
            self._jump_to(item.exercise_index)

    def on_exercise_list_reset_requested(
        self, event: "ExerciseList.ResetRequested"
    ) -> None:
        """``x`` in the list resets the highlighted exercise in place."""
        self._reset_exercise(self.state.exercises[event.index])
        self.query_one("#exercise_list", ExerciseList).populate(self.state)

    def _reset_exercise(self, ex) -> None:
        """Restore an exercise's source from the bundled original."""
        original = cli.DATA_DIR / ex.rel_path()
        if not original.is_file():
            self.query_one("#status", Static).update(
                f"[red]No bundled original for[/red] {ex.dir}/{ex.name}."
            )
            return
        shutil.copy2(original, self.state.exercise_path(ex))
        self.state.set_pending(ex.name)
        self.query_one("#status", Static).update(
            f"[cyan]Reset[/cyan] {ex.dir}/{ex.name} to its original state."
        )
        # Only reload/recheck if we reset the exercise currently in view.
        if ex.name == self.state.current_exercise().name:
            if self._code_visible:
                self._code_dirty = False
                self._render_code()
            self._check_current()
        else:
            self._update_progress()

    def action_reset(self) -> None:
        self._reset_exercise(self.state.current_exercise())

    def action_code(self) -> None:
        """Toggle an inline, editable view of the exercise source."""
        code = self.query_one("#code", TextArea)
        output = self.query_one("#output", RichLog)
        if self._code_visible:
            code.remove_class("visible")
            output.remove_class("compact")
            self._code_visible = False
            return
        self._code_visible = True
        code.add_class("visible")
        # Shrink the output pane so the editor is the main workspace.
        output.add_class("compact")
        self._render_code()
        code.focus()

    def on_text_area_changed(self, event: TextArea.Changed) -> None:
        """Track unsaved edits so the status line can nudge for ctrl+s."""
        if event.text_area.id != "code" or not self._code_visible:
            return
        # Ignore the Changed event that a programmatic load_text posts: the
        # buffer still matches the baseline we just loaded, so it's not an edit.
        if event.text_area.text == self._code_baseline:
            self._code_dirty = False
            return
        if not self._code_dirty:
            self._code_dirty = True
            self.query_one("#status", Static).update(
                "[yellow]Unsaved changes.[/yellow] "
                "Press [bold]ctrl+s[/bold] to save and recheck."
            )

    def action_save(self) -> None:
        """Write the editor buffer back to the exercise file, then recheck."""
        if not self._code_visible:
            self.query_one("#status", Static).update(
                "[yellow]Open the editor with [bold]c[/bold] first.[/yellow]"
            )
            return
        code = self.query_one("#code", TextArea)
        if code.read_only:
            return
        ex = self.state.current_exercise()
        path = self.state.exercise_path(ex)
        try:
            path.write_text(code.text, encoding="utf-8")
        except OSError as exc:
            self.query_one("#status", Static).update(
                f"[red]Couldn't save:[/red] {exc}"
            )
            return
        self._code_dirty = False
        self._code_baseline = code.text
        self.query_one("#status", Static).update(
            f"[cyan]Saved[/cyan] {ex.dir}/{ex.name}. Rechecking …"
        )
        self._check_current()

    def _register_cpp_highlighting(self) -> None:
        """Enable C++ syntax highlighting in the editor if the grammar is present.

        Highlighting needs the optional ``tree-sitter`` + ``tree-sitter-cpp``
        packages. They aren't hard dependencies, so if the import fails we just
        leave the editor as plain text — it's still fully editable.
        """
        try:
            from tree_sitter import Language
            import tree_sitter_cpp as tsc
        except ImportError:
            return
        # The C++ grammar's highlight query is only a *delta* over the C
        # grammar's: it covers C++-only constructs (namespaces, templates) but
        # not the base C constructs (#include, primitive types, return, string
        # literals, ...). Prepend the C query so both layers highlight.
        query = tsc.HIGHLIGHTS_QUERY
        try:
            import tree_sitter_c as tsc_c

            query = tsc_c.HIGHLIGHTS_QUERY + "\n" + query
        except ImportError:
            pass
        try:
            code = self.query_one("#code", TextArea)
            code.register_language("cpp", Language(tsc.language()), query)
            self._code_language = "cpp"
        except Exception:
            # Any grammar/ABI mismatch: fall back to plain text silently.
            self._code_language = None

    def _render_code(self) -> None:
        """Load the current exercise source into the editable code pane."""
        code = self.query_one("#code", TextArea)
        ex = self.state.current_exercise()
        path = self.state.exercise_path(ex)
        try:
            source = path.read_text(encoding="utf-8")
        except OSError as exc:
            text = f"// Could not read {path}: {exc}\n"
            self._code_baseline = text
            code.load_text(text)
            code.read_only = True
            return
        code.read_only = False
        self._code_baseline = source
        code.load_text(source)
        if self._code_language:
            code.language = self._code_language
        self._code_dirty = False

    def _refresh_code_if_visible(self) -> None:
        # Don't reload while the learner has unsaved edits in the pane —
        # that would wipe their work. Their own save already synced the file.
        if self._code_visible and not self._code_dirty:
            self._render_code()

    def action_edit(self) -> None:
        """Open the current exercise in the user's editor/IDE."""
        ex = self.state.current_exercise()
        path = str(self.state.exercise_path(ex))
        try:
            if sys.platform == "win32":
                os.startfile(path)  # type: ignore[attr-defined]
            elif sys.platform == "darwin":
                subprocess.Popen(["open", path])
            else:
                editor = os.environ.get("EDITOR") or os.environ.get("VISUAL")
                if editor:
                    subprocess.Popen([editor, path])
                else:
                    subprocess.Popen(["xdg-open", path])
        except OSError as exc:
            self.query_one("#status", Static).update(
                f"[red]Couldn't open editor:[/red] {exc}"
            )
            return
        self.query_one("#status", Static).update(
            f"[cyan]Opened[/cyan] {ex.dir}/{ex.name} in your editor. "
            "Edit, save, and I'll recheck automatically."
        )


def run_watch_app() -> int:
    """Entry point for ``cpplings watch``: resolve state + toolchain, run TUI."""
    working_dir = cli.find_working_dir()
    if working_dir is None:
        print(
            "No cpplings workspace found here.\n"
            "Run `cpplings init` first to set up the exercises."
        )
        return 1

    try:
        toolchain = detect_toolchain()
    except ToolchainError as exc:
        print(str(exc))
        return 1

    info = InfoFile.load(working_dir / "info.toml")
    state = AppState(working_dir, info)

    app = CpplingsApp(state, toolchain)
    app.run()
    return 0
