"""End-to-end runner tests against the real detected toolchain.

These are skipped automatically if no C++ compiler is available, so the suite
still passes in a bare CI environment.
"""

from __future__ import annotations

from pathlib import Path

import pytest

from cpplings.info_file import ExerciseInfo
from cpplings.runner import CheckStatus, check_exercise
from cpplings.toolchain import ToolchainError, detect_toolchain

DATA_DIR = Path(__file__).resolve().parent.parent / "cpplings" / "data"
HEADER_DIR = DATA_DIR  # cpplings_test.hpp lives here


@pytest.fixture(scope="module")
def toolchain():
    try:
        return detect_toolchain()
    except ToolchainError:
        pytest.skip("no C++ compiler available")


def _write(tmp_path: Path, name: str, body: str) -> Path:
    src = tmp_path / name
    src.write_text(body, encoding="utf-8")
    return src


def _ex(name: str) -> ExerciseInfo:
    return ExerciseInfo(name=name, dir="t", hint="", test=True)


def test_passing_exercise_is_done(tmp_path: Path, toolchain) -> None:
    src = _write(
        tmp_path,
        "ok.cpp",
        '#include "cpplings_test.hpp"\n'
        "CPPLINGS_TEST(t) { CPPLINGS_ASSERT_EQ(2 + 2, 4); }\n",
    )
    result = check_exercise(_ex("ok"), src, toolchain, HEADER_DIR)
    assert result.status is CheckStatus.DONE


def test_marker_blocks_completion(tmp_path: Path, toolchain) -> None:
    src = _write(
        tmp_path,
        "marked.cpp",
        "// I AM NOT DONE\n"
        '#include "cpplings_test.hpp"\n'
        "CPPLINGS_TEST(t) { CPPLINGS_ASSERT(true); }\n",
    )
    result = check_exercise(_ex("marked"), src, toolchain, HEADER_DIR)
    assert result.status is CheckStatus.NOT_DONE_MARKER


def test_compile_error(tmp_path: Path, toolchain) -> None:
    src = _write(tmp_path, "bad.cpp", "int main() { return }\n")
    result = check_exercise(_ex("bad"), src, toolchain, HEADER_DIR)
    assert result.status is CheckStatus.COMPILE_FAILED


def test_failing_assertion(tmp_path: Path, toolchain) -> None:
    src = _write(
        tmp_path,
        "fail.cpp",
        '#include "cpplings_test.hpp"\n'
        "CPPLINGS_TEST(t) { CPPLINGS_ASSERT_EQ(1, 2); }\n",
    )
    result = check_exercise(_ex("fail"), src, toolchain, HEADER_DIR)
    assert result.status is CheckStatus.RUN_FAILED
