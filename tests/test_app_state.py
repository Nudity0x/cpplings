"""Tests for AppState progress tracking and state-file persistence."""

from __future__ import annotations

from pathlib import Path

from cpplings.app_state import AppState, has_not_done_marker
from cpplings.info_file import ExerciseInfo, InfoFile


def _info() -> InfoFile:
    return InfoFile(
        format_version=1,
        exercises=[
            ExerciseInfo(name="a", dir="00_intro", hint="", test=False),
            ExerciseInfo(name="b", dir="00_intro", hint=""),
            ExerciseInfo(name="c", dir="01_x", hint=""),
        ],
    )


def test_marker_detection() -> None:
    assert has_not_done_marker("// I AM NOT DONE\nint main(){}")
    assert not has_not_done_marker("int main(){}")
    # Block-comment and indented forms of the marker still count.
    assert has_not_done_marker("  //   I AM NOT DONE  ")
    assert has_not_done_marker("/* I AM NOT DONE */")
    # Prose that merely *mentions* the marker must NOT count, or the exercise
    # would be permanently uncompletable (regression: intro1 did this).
    assert not has_not_done_marker(
        '// remove the "I AM NOT DONE" line below to continue\n'
    )
    assert not has_not_done_marker(
        "// When solved, delete the I AM NOT DONE comment.\n"
    )


def test_fresh_state_starts_at_zero(tmp_path: Path) -> None:
    state = AppState(tmp_path, _info())
    assert state.current_ind == 0
    assert state.n_done == 0
    assert state.n_pending == 3


def test_mark_done_persists_and_advances(tmp_path: Path) -> None:
    state = AppState(tmp_path, _info())
    state.mark_done_and_persist("a")
    assert state.is_done("a")

    # A fresh AppState reads the same state file back.
    reloaded = AppState(tmp_path, _info())
    assert reloaded.is_done("a")
    assert reloaded.n_done == 1


def test_next_pending_skips_done(tmp_path: Path) -> None:
    state = AppState(tmp_path, _info())
    state.mark_done_and_persist("b")
    # From index 0, the next pending should skip b (index 1) -> c (index 2).
    assert state.next_pending_ind() == 2


def test_current_jumps_past_done_on_load(tmp_path: Path) -> None:
    state = AppState(tmp_path, _info())
    state.set_current(0)
    state.mark_done_and_persist("a")

    reloaded = AppState(tmp_path, _info())
    # 'a' (index 0) is done, so load should move to the first pending (index 1).
    assert reloaded.current_ind == 1


def test_set_pending_reverts(tmp_path: Path) -> None:
    state = AppState(tmp_path, _info())
    state.mark_done_and_persist("a")
    state.set_pending("a")
    assert not state.is_done("a")
    assert state.n_done == 0
