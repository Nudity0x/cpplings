"""Tests for CLI helpers and the bundled section READMEs."""

from __future__ import annotations

from pathlib import Path

from cpplings import cli
from cpplings.app_state import AppState
from cpplings.info_file import ExerciseInfo, InfoFile


def _info() -> InfoFile:
    return InfoFile(
        format_version=1,
        exercises=[
            ExerciseInfo(name="a", dir="00_intro", hint=""),
            ExerciseInfo(name="b", dir="00_intro", hint=""),
            ExerciseInfo(name="c", dir="01_x", hint=""),
        ],
    )


def test_every_section_has_a_readme() -> None:
    """Each section directory in the bundled curriculum must ship a README."""
    info = InfoFile.load(cli.DATA_DIR / "info.toml")
    sections = {ex.dir for ex in info.exercises}
    missing = [
        d for d in sorted(sections)
        if not (cli.DATA_DIR / "exercises" / d / "README.md").is_file()
    ]
    assert missing == []


def test_resolve_defaults_to_first_pending(tmp_path: Path) -> None:
    """With no name, resolve should skip a done 'current' to the first pending."""
    state = AppState(tmp_path, _info())
    # Mark the current (index 0) done; resolve should move past it.
    state.mark_done_and_persist("a")
    state.set_current(0)
    resolved = cli._resolve_exercise(state, None)
    assert resolved.name == "b"


def test_resolve_named_exercise(tmp_path: Path) -> None:
    state = AppState(tmp_path, _info())
    assert cli._resolve_exercise(state, "c").name == "c"


def test_readme_command(tmp_path: Path, capsys) -> None:
    """`cpplings readme` prints the section README for the current exercise."""
    dest = tmp_path / "cpplings"
    assert cli.cmd_init(str(dest)) == 0
    info = InfoFile.load(dest / "info.toml")
    state = AppState(dest, info)
    ex = state.current_exercise()

    # cmd_readme resolves the working dir from CWD, so run from there.
    import os

    old = os.getcwd()
    os.chdir(dest)
    try:
        assert cli.cmd_readme(None) == 0
    finally:
        os.chdir(old)

    out = capsys.readouterr().out
    expected = (dest / ex.readme_rel_path()).read_text(encoding="utf-8")
    # First markdown heading of the section README should appear in output.
    assert expected.splitlines()[0] in out
