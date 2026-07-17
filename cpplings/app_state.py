"""Application state: current exercise, done set, and progress persistence.

Mirrors rustlings' ``app_state.rs`` and its state-file format. Progress is
stored next to the exercises in a plain-text file so it survives restarts and
is trivial to inspect or delete.

State file (``.cpplings-state.txt``) format::

    DON'T EDIT THIS FILE!      <- header comment line
                               <- blank line
    <current exercise name>    <- line 3
                               <- blank line
    <done exercise name>       <- one per remaining line
    <done exercise name>
    ...

The "I AM NOT DONE" marker is the second gate on completion: an exercise counts
as done only when it both passes (compile + tests) *and* has had the marker
removed. This prevents auto-skipping exercises that already happen to compile.
"""

from __future__ import annotations

from pathlib import Path
from typing import List, Optional

from .info_file import ExerciseInfo, InfoFile

STATE_FILE_NAME = ".cpplings-state.txt"
STATE_FILE_HEADER = "DON'T EDIT THIS FILE!"
NOT_DONE_MARKER = "I AM NOT DONE"


def has_not_done_marker(source: str) -> bool:
    """Return True if the exercise source still contains the not-done marker.

    The marker lives on its own comment line, e.g. ``// I AM NOT DONE``. We match
    per line rather than by raw substring so that instructional prose *mentioning*
    the marker (for example, the intro exercise explaining the workflow) doesn't
    count and leave the exercise permanently uncompletable.

    A line matches when, after stripping whitespace and leading C++ comment
    punctuation (``//`` or ``/*``), its content equals the marker exactly.
    Matching is case-sensitive, mirroring rustlings.
    """
    for line in source.splitlines():
        stripped = line.strip()
        # Drop a leading line-comment or block-comment opener.
        if stripped.startswith("//"):
            stripped = stripped[2:]
        elif stripped.startswith("/*"):
            stripped = stripped[2:]
        # Drop a trailing block-comment closer if present.
        if stripped.endswith("*/"):
            stripped = stripped[:-2]
        if stripped.strip() == NOT_DONE_MARKER:
            return True
    return False


class AppState:
    """Tracks progress across the exercise list and persists it to disk.

    ``working_dir`` is the directory produced by ``cpplings init`` (holds
    ``exercises/``, ``solutions/``, ``info.toml`` and the state file).
    """

    def __init__(self, working_dir: Path, info: InfoFile) -> None:
        self.working_dir = working_dir
        self.info = info
        self.exercises: List[ExerciseInfo] = info.exercises
        self.state_file = working_dir / STATE_FILE_NAME
        self.current_ind: int = 0
        self._done: set = set()  # exercise names known to be done
        self._load()

    # ---- progress queries -------------------------------------------------

    @property
    def n_total(self) -> int:
        return len(self.exercises)

    @property
    def n_done(self) -> int:
        return len(self._done)

    @property
    def n_pending(self) -> int:
        return self.n_total - self.n_done

    def is_done(self, name: str) -> bool:
        return name in self._done

    def current_exercise(self) -> ExerciseInfo:
        return self.exercises[self.current_ind]

    def exercise_path(self, ex: ExerciseInfo) -> Path:
        """Absolute path to an exercise's source file."""
        return self.working_dir / ex.rel_path()

    def solution_path(self, ex: ExerciseInfo) -> Path:
        """Absolute path to an exercise's reference solution."""
        return self.working_dir / ex.solution_rel_path()

    def index_of(self, name: str) -> Optional[int]:
        for i, ex in enumerate(self.exercises):
            if ex.name == name:
                return i
        return None

    # ---- mutations --------------------------------------------------------

    def set_current(self, ind: int) -> None:
        if not 0 <= ind < self.n_total:
            raise IndexError("exercise index out of range")
        self.current_ind = ind
        self._write()

    def set_status(self, name: str, done: bool) -> bool:
        """Mark an exercise done/pending. Returns True if the status changed."""
        changed = (name in self._done) != done
        if not changed:
            return False
        if done:
            self._done.add(name)
        else:
            self._done.discard(name)
        return True

    def set_pending(self, name: str) -> None:
        if self.set_status(name, False):
            self._write()

    def mark_done_and_persist(self, name: str) -> None:
        if self.set_status(name, True):
            self._write()

    def next_pending_ind(self) -> Optional[int]:
        """Index of the next pending exercise after the current, wrapping around.

        Searches forward from just after the current exercise, then wraps to the
        beginning. Returns None if every exercise is done.
        """
        n = self.n_total
        for offset in range(1, n + 1):
            ind = (self.current_ind + offset) % n
            if not self.is_done(self.exercises[ind].name):
                return ind
        return None

    def first_pending_ind(self) -> Optional[int]:
        for i, ex in enumerate(self.exercises):
            if not self.is_done(ex.name):
                return i
        return None

    # ---- persistence ------------------------------------------------------

    def _load(self) -> None:
        """Read the state file if present; otherwise start fresh at exercise 0.

        Unknown exercise names (e.g. after the curriculum changes) are ignored.
        If the recorded current exercise no longer exists, we fall back to the
        first pending one.
        """
        if not self.state_file.is_file():
            self.current_ind = self.first_pending_ind() or 0
            return

        lines = self.state_file.read_text(encoding="utf-8").split("\n")
        # lines[0] = header, lines[1] = blank, lines[2] = current, lines[3] = blank
        valid_names = {ex.name for ex in self.exercises}
        if len(lines) >= 3:
            current_name = lines[2].strip()
            ind = self.index_of(current_name)
            if ind is not None:
                self.current_ind = ind

        for line in lines[4:]:
            name = line.strip()
            if name and name in valid_names:
                self._done.add(name)

        # If the stored current exercise was already done, jump to first pending.
        if self.is_done(self.current_exercise().name):
            pending = self.first_pending_ind()
            if pending is not None:
                self.current_ind = pending

    def _write(self) -> None:
        parts = [STATE_FILE_HEADER, "", self.current_exercise().name, ""]
        # Preserve curriculum order for the done list for stable diffs.
        for ex in self.exercises:
            if ex.name in self._done:
                parts.append(ex.name)
        self.state_file.write_text("\n".join(parts) + "\n", encoding="utf-8")
