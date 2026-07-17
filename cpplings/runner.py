"""Compile-and-run check loop for a single exercise.

Mirrors rustlings' ``exercise.rs::run``, adapted for C++:

  1. Read the source. If the "I AM NOT DONE" marker is present, the exercise is
     Pending regardless of whether it compiles.
  2. Compile with the detected toolchain. A nonzero exit is a compile failure;
     the compiler's stdout/stderr is captured for display.
  3. Run the produced binary. A nonzero exit is a runtime/test failure (the
     bundled test header calls ``exit(1)`` on the first failed assertion).
  4. If it compiled, ran cleanly, and the marker is gone -> Done.

Compilation happens in a temp directory so exercise folders stay clean of
build artifacts (.exe/.obj).
"""

from __future__ import annotations

import subprocess
import tempfile
from dataclasses import dataclass
from enum import Enum, auto
from pathlib import Path
from typing import Optional

from .app_state import has_not_done_marker
from .info_file import ExerciseInfo
from .toolchain import Toolchain


class CheckStatus(Enum):
    """Outcome of checking one exercise."""

    DONE = auto()  # compiled, ran clean, marker removed
    COMPILE_FAILED = auto()
    RUN_FAILED = auto()  # compiled but the binary exited nonzero (tests failed)
    NOT_DONE_MARKER = auto()  # passed but the marker is still present


@dataclass
class CheckResult:
    """Result of a check: status plus captured output for the TUI to render."""

    status: CheckStatus
    output: str

    @property
    def passed(self) -> bool:
        """True only when the exercise is fully solved (Done)."""
        return self.status is CheckStatus.DONE


# A generous ceiling so a runaway exercise (e.g. an infinite loop the learner
# wrote) can't wedge the watch loop forever.
COMPILE_TIMEOUT_S = 30
RUN_TIMEOUT_S = 10


def _run(
    cmd, cwd: Optional[Path], timeout: int, env: Optional[dict] = None
) -> subprocess.CompletedProcess:
    """Run a command, capturing merged text output; never raises on nonzero."""
    return subprocess.run(
        cmd,
        cwd=str(cwd) if cwd else None,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
        timeout=timeout,
        check=False,
        env=env,
    )


def check_exercise(
    ex: ExerciseInfo,
    source_path: Path,
    toolchain: Toolchain,
    include_dir: Path,
) -> CheckResult:
    """Compile and run one exercise, returning its :class:`CheckResult`.

    ``include_dir`` is the directory containing ``cpplings_test.hpp`` so the
    ``#include "cpplings_test.hpp"`` in test exercises resolves regardless of
    where the exercise file lives.
    """
    source = source_path.read_text(encoding="utf-8")
    marker_present = has_not_done_marker(source)
    env = toolchain.subprocess_env()

    with tempfile.TemporaryDirectory(prefix="cpplings_") as tmp:
        tmp_dir = Path(tmp)
        output_bin = tmp_dir / (source_path.stem + toolchain.executable_suffix())

        compile_cmd = toolchain.compile_command(source_path, output_bin)
        # Let the exercise include the bundled header by name.
        if toolchain.family == "msvc":
            compile_cmd.insert(1, f"/I{include_dir}")
        else:
            compile_cmd[1:1] = ["-I", str(include_dir)]

        try:
            compiled = _run(compile_cmd, cwd=tmp_dir, timeout=COMPILE_TIMEOUT_S, env=env)
        except subprocess.TimeoutExpired:
            return CheckResult(
                CheckStatus.COMPILE_FAILED,
                f"Compilation timed out after {COMPILE_TIMEOUT_S}s.",
            )

        if compiled.returncode != 0:
            return CheckResult(CheckStatus.COMPILE_FAILED, compiled.stdout or "")

        try:
            ran = _run([str(output_bin)], cwd=tmp_dir, timeout=RUN_TIMEOUT_S, env=env)
        except subprocess.TimeoutExpired:
            return CheckResult(
                CheckStatus.RUN_FAILED,
                f"The exercise timed out after {RUN_TIMEOUT_S}s "
                "(did you write an infinite loop?).",
            )

        if ran.returncode != 0:
            return CheckResult(CheckStatus.RUN_FAILED, ran.stdout or "")

        # Compiled and ran cleanly. The marker is the final gate.
        if marker_present:
            return CheckResult(CheckStatus.NOT_DONE_MARKER, ran.stdout or "")

        return CheckResult(CheckStatus.DONE, ran.stdout or "")
