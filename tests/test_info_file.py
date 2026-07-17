"""Tests for info.toml parsing."""

from __future__ import annotations

from pathlib import Path

import pytest

from cpplings.info_file import InfoFile, InfoFileError


def _write(tmp_path: Path, text: str) -> Path:
    p = tmp_path / "info.toml"
    p.write_text(text, encoding="utf-8")
    return p


def test_parses_exercises(tmp_path: Path) -> None:
    info = InfoFile.load(
        _write(
            tmp_path,
            """
format_version = 1
welcome_message = "hi"

[[exercises]]
name = "intro1"
dir = "00_intro"
hint = "just remove the marker"
test = false

[[exercises]]
name = "variables1"
dir = "01_variables"
hint = "add a type"
""",
        )
    )
    assert info.format_version == 1
    assert info.welcome_message == "hi"
    assert len(info.exercises) == 2

    intro, variables = info.exercises
    assert intro.name == "intro1"
    assert intro.test is False
    assert intro.rel_path() == Path("exercises/00_intro/intro1.cpp")
    assert intro.solution_rel_path() == Path("solutions/00_intro/intro1.cpp")
    assert intro.readme_rel_path() == Path("exercises/00_intro/README.md")
    # test defaults to True when omitted.
    assert variables.test is True


def test_missing_file(tmp_path: Path) -> None:
    with pytest.raises(InfoFileError):
        InfoFile.load(tmp_path / "nope.toml")


def test_empty_exercises(tmp_path: Path) -> None:
    with pytest.raises(InfoFileError):
        InfoFile.load(_write(tmp_path, "format_version = 1\n"))


def test_missing_required_key(tmp_path: Path) -> None:
    with pytest.raises(InfoFileError):
        InfoFile.load(
            _write(
                tmp_path,
                """
[[exercises]]
dir = "00_intro"
hint = "no name"
""",
            )
        )
