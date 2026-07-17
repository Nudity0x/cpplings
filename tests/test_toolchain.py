"""Tests for toolchain flag construction and override resolution."""

from __future__ import annotations

from pathlib import Path

import pytest

from cpplings import toolchain as tc
from cpplings.toolchain import Toolchain, ToolchainError, detect_toolchain


def test_gcc_compile_command() -> None:
    t = Toolchain(path="g++", family=tc.FAMILY_GCC, name="g++")
    cmd = t.compile_command(Path("ex.cpp"), Path("out"))
    assert cmd[0] == "g++"
    assert "-std=c++17" in cmd
    assert "-o" in cmd
    assert cmd[-1] == "out"


def test_msvc_compile_command() -> None:
    t = Toolchain(path="cl", family=tc.FAMILY_MSVC, name="cl")
    cmd = t.compile_command(Path("ex.cpp"), Path("out"))
    assert cmd[0] == "cl"
    assert "/std:c++17" in cmd
    assert any(a.startswith("/Fe:") for a in cmd)


def test_family_for() -> None:
    assert tc._family_for("cl.exe") == tc.FAMILY_MSVC
    assert tc._family_for("g++") == tc.FAMILY_GCC
    assert tc._family_for("clang++") == tc.FAMILY_GCC


def test_override_missing_raises(monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.setattr(tc.shutil, "which", lambda _n: None)
    with pytest.raises(ToolchainError):
        detect_toolchain(override="definitely-not-a-compiler-xyz")


def test_override_resolved_on_path(monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.setattr(
        tc.shutil, "which", lambda n: r"C:\bin\clang++.exe" if n == "clang++" else None
    )
    t = detect_toolchain(override="clang++")
    assert t.family == tc.FAMILY_GCC
