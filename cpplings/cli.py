"""Command dispatch for the ``cpplings`` CLI.

Commands:
  * ``init``   — copy the bundled curriculum (exercises, solutions, header,
                 info.toml) into a working directory and create the state file.
  * ``watch``  — the main loop: launch the TUI, auto-rechecking on save.
  * ``run``    — check a single exercise once and print the result.
  * ``list``   — print every exercise with its done/pending status.
  * ``hint``   — print the hint for an exercise.
  * ``reset``  — restore an exercise's source from the bundled original.
  * ``readme`` — print the section README (concept explainer) for an exercise.
  * ``verify`` — (dev) compile+run every *solution* to prove the curriculum.

The "working directory" is where ``init`` placed the curriculum. Every command
except ``init`` resolves it by walking up from the CWD looking for ``info.toml``
next to an ``exercises`` directory.
"""

from __future__ import annotations

import shutil
import sys
from pathlib import Path
from typing import Optional

from .app_state import AppState
from .info_file import ExerciseInfo, InfoFile
from .runner import CheckStatus, check_exercise
from .toolchain import ToolchainError, detect_toolchain

# The bundled curriculum shipped as package data.
DATA_DIR = Path(__file__).parent / "data"
TEST_HEADER_NAME = "cpplings_test.hpp"


# ---- working directory resolution ------------------------------------------


def _looks_like_working_dir(path: Path) -> bool:
    return (path / "info.toml").is_file() and (path / "exercises").is_dir()


def find_working_dir(start: Optional[Path] = None) -> Optional[Path]:
    """Walk up from ``start`` (default CWD) to find the curriculum root."""
    current = (start or Path.cwd()).resolve()
    for candidate in (current, *current.parents):
        if _looks_like_working_dir(candidate):
            return candidate
    return None


def _require_working_dir() -> Path:
    wd = find_working_dir()
    if wd is None:
        print(
            "No cpplings workspace found here.\n"
            "Run `cpplings init` first to set up the exercises.",
            file=sys.stderr,
        )
        raise SystemExit(1)
    return wd


def _load_state(working_dir: Path) -> AppState:
    info = InfoFile.load(working_dir / "info.toml")
    return AppState(working_dir, info)


# ---- init -------------------------------------------------------------------


def cmd_init(target: Optional[str]) -> int:
    """Copy the bundled curriculum into ``target`` (default ``./cpplings``)."""
    dest = Path(target).resolve() if target else (Path.cwd() / "cpplings").resolve()

    if dest.exists() and any(dest.iterdir()):
        if _looks_like_working_dir(dest):
            print(f"cpplings is already initialized at {dest}.")
            return 0
        print(f"Refusing to init: {dest} exists and is not empty.", file=sys.stderr)
        return 1

    dest.mkdir(parents=True, exist_ok=True)
    for name in ("exercises", "solutions"):
        shutil.copytree(DATA_DIR / name, dest / name)
    shutil.copy2(DATA_DIR / "info.toml", dest / "info.toml")
    shutil.copy2(DATA_DIR / TEST_HEADER_NAME, dest / TEST_HEADER_NAME)

    # Prime state so the first `watch` starts at exercise 0.
    _load_state(dest)

    print(
        f"Initialized cpplings in {dest}\n\n"
        f"  cd {dest}\n"
        "  cpplings watch\n\n"
        "Then open the first exercise, fix it, remove the "
        '"// I AM NOT DONE" line, and save.'
    )
    return 0


# ---- helpers for single-exercise commands ----------------------------------


def _resolve_exercise(state: AppState, name: Optional[str]) -> ExerciseInfo:
    """Return the named exercise, or the next pending one if ``name`` is None.

    With no name we mirror rustlings: operate on the exercise the user is
    currently on. The state loader keeps ``current`` pointed at the first
    pending exercise, but if it happens to be done (e.g. the very last one was
    just finished) we fall back to the first pending so ``run``/``hint``/
    ``reset`` still target something useful.
    """
    if name is None:
        if state.is_done(state.current_exercise().name):
            pending = state.first_pending_ind()
            if pending is not None:
                return state.exercises[pending]
        return state.current_exercise()
    ind = state.index_of(name)
    if ind is None:
        print(f"No exercise named '{name}'.", file=sys.stderr)
        raise SystemExit(1)
    return state.exercises[ind]


def _detect_or_exit():
    try:
        return detect_toolchain()
    except ToolchainError as exc:
        print(str(exc), file=sys.stderr)
        raise SystemExit(1)


# ---- run --------------------------------------------------------------------


def cmd_run(name: Optional[str]) -> int:
    """Check a single exercise once and print the outcome."""
    working_dir = _require_working_dir()
    state = _load_state(working_dir)
    toolchain = _detect_or_exit()
    ex = _resolve_exercise(state, name)

    result = check_exercise(
        ex, state.exercise_path(ex), toolchain, working_dir
    )
    if result.output.strip():
        print(result.output.rstrip())

    if result.status is CheckStatus.DONE:
        state.mark_done_and_persist(ex.name)
        print(f"\n{ex.name}: done")
        return 0

    state.set_pending(ex.name)
    if result.status is CheckStatus.NOT_DONE_MARKER:
        print(
            f"\n{ex.name}: compiles and passes! "
            'Remove the "// I AM NOT DONE" comment to continue.'
        )
    elif result.status is CheckStatus.COMPILE_FAILED:
        print(f"\n{ex.name}: compile error")
    else:
        print(f"\n{ex.name}: tests failed")
    return 1


# ---- list -------------------------------------------------------------------


def cmd_list() -> int:
    working_dir = _require_working_dir()
    state = _load_state(working_dir)
    for ex in state.exercises:
        mark = "DONE" if state.is_done(ex.name) else "    "
        pointer = ">" if ex is state.current_exercise() else " "
        print(f"{pointer} [{mark}] {ex.dir}/{ex.name}")
    print(f"\nProgress: {state.n_done}/{state.n_total}")
    return 0


# ---- hint -------------------------------------------------------------------


def cmd_hint(name: Optional[str]) -> int:
    working_dir = _require_working_dir()
    state = _load_state(working_dir)
    ex = _resolve_exercise(state, name)
    print(ex.hint or "(no hint for this exercise)")
    return 0


# ---- readme -----------------------------------------------------------------


def cmd_readme(name: Optional[str]) -> int:
    """Print the section README for an exercise (the concept explainer)."""
    working_dir = _require_working_dir()
    state = _load_state(working_dir)
    ex = _resolve_exercise(state, name)
    readme = working_dir / ex.readme_rel_path()
    if not readme.is_file():
        print(f"No README for the '{ex.dir}' section.", file=sys.stderr)
        return 1
    print(readme.read_text(encoding="utf-8").rstrip())
    return 0


# ---- reset ------------------------------------------------------------------


def cmd_reset(name: Optional[str]) -> int:
    """Overwrite an exercise's source with the bundled original."""
    working_dir = _require_working_dir()
    state = _load_state(working_dir)
    ex = _resolve_exercise(state, name)

    original = DATA_DIR / ex.rel_path()
    if not original.is_file():
        print(f"No bundled original for '{ex.name}'.", file=sys.stderr)
        return 1

    shutil.copy2(original, state.exercise_path(ex))
    state.set_pending(ex.name)
    print(f"Reset {ex.dir}/{ex.name} to its original state.")
    return 0


# ---- verify -----------------------------------------------------------------


def cmd_verify() -> int:
    """Compile+run every solution to confirm the curriculum is correct.

    Solutions must not contain the not-done marker, so a correct solution
    yields ``CheckStatus.DONE``. Any other status is a curriculum bug.
    """
    working_dir = find_working_dir() or DATA_DIR
    info = InfoFile.load(working_dir / "info.toml")
    toolchain = _detect_or_exit()

    failures = 0
    for ex in info.exercises:
        sol_path = working_dir / ex.solution_rel_path()
        if not sol_path.is_file():
            print(f"MISSING  {ex.dir}/{ex.name}: no solution file")
            failures += 1
            continue
        result = check_exercise(ex, sol_path, toolchain, working_dir)
        if result.status is CheckStatus.DONE:
            print(f"OK       {ex.dir}/{ex.name}")
        else:
            print(f"FAIL     {ex.dir}/{ex.name}: {result.status.name}")
            if result.output.strip():
                print("    " + result.output.strip().replace("\n", "\n    "))
            failures += 1

    print(
        f"\nVerified {len(info.exercises) - failures}/{len(info.exercises)} "
        "solutions."
    )
    return 1 if failures else 0
