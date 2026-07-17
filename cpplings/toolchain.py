"""Toolchain detection and command construction for cpplings.

C++ has no single blessed toolchain, so we detect whatever the learner has:
an explicit override via ``CPPLINGS_CXX``, then ``g++``, ``clang++``, and
finally MSVC ``cl.exe``. Detection also scans common install locations
(MSYS2, Visual Studio) because those compilers are frequently not on PATH,
especially on Windows.

Each detected compiler knows how to build a *compile* command and, for MSVC,
the flags differ from the GCC/Clang family. Running the produced binary is
handled by the caller (see :mod:`cpplings.runner`).
"""

from __future__ import annotations

import glob
import os
import shutil
from dataclasses import dataclass
from pathlib import Path
from typing import List, Optional

CPP_STANDARD = "c++17"

# Compiler "families" determine flag syntax.
FAMILY_GCC = "gcc"  # g++ and clang++ share the GCC-style CLI.
FAMILY_MSVC = "msvc"  # cl.exe uses /flags.


class ToolchainError(RuntimeError):
    """Raised when no usable C++ compiler can be found."""


@dataclass(frozen=True)
class Toolchain:
    """A resolved C++ compiler and how to drive it."""

    path: str
    family: str
    name: str

    def compile_command(self, source: Path, output: Path) -> List[str]:
        """Build the argv that compiles ``source`` into the executable ``output``."""
        if self.family == FAMILY_MSVC:
            # /Fe: sets the output exe; /Fo sets the intermediate obj so we
            # don't litter the exercise directory with a .obj next to the .cpp.
            # /W4 + /WX hold exercises to a high bar and treat warnings as
            # errors, so sloppy-but-compiling C++ (e.g. an unused variable or a
            # narrowing conversion) counts as "not done yet".
            obj = output.with_suffix(".obj")
            return [
                self.path,
                f"/std:{CPP_STANDARD}",
                "/EHsc",
                "/nologo",
                "/W4",
                "/WX",
                "/permissive-",
                str(source),
                f"/Fe:{output}",
                f"/Fo:{obj}",
            ]
        # Warnings are part of correctness here. -Werror turns them into
        # compile failures so the curriculum can't teach code that merely
        # happens to compile. -Wshadow/-Wconversion/-Wold-style-cast catch the
        # subtle-but-improper C++ that -Wall alone lets through.
        return [
            self.path,
            f"-std={CPP_STANDARD}",
            "-Wall",
            "-Wextra",
            "-Wpedantic",
            "-Wshadow",
            "-Wconversion",
            "-Wsign-conversion",
            "-Wold-style-cast",
            "-Wnon-virtual-dtor",
            "-Werror",
            str(source),
            "-o",
            str(output),
        ]

    def executable_suffix(self) -> str:
        """Suffix for the compiled binary on this platform."""
        return ".exe" if os.name == "nt" else ""

    def subprocess_env(self) -> dict:
        """Environment for running the compiler and the binaries it produces.

        MSYS2/MinGW compilers live in a ``bin`` directory that also holds the
        runtime DLLs (libstdc++, libgcc, libwinpthread) that both ``g++`` itself
        and the compiled programs link against. If that directory isn't on
        ``PATH``, launching them fails silently on Windows (exit 1, no output).

        We prepend the compiler's own directory to a copy of the current
        environment so detection-by-full-path just works, with no ``PATH``
        wrangling required from the user.
        """
        env = os.environ.copy()
        compiler_dir = str(Path(self.path).parent)
        existing = env.get("PATH", "")
        if compiler_dir not in existing.split(os.pathsep):
            env["PATH"] = (
                compiler_dir + os.pathsep + existing if existing else compiler_dir
            )
        return env


def _candidate_paths_gcc() -> List[str]:
    """Common off-PATH locations for g++/clang++ on Windows (MSYS2, etc.)."""
    patterns = [
        r"C:\msys64\ucrt64\bin\g++.exe",
        r"C:\msys64\mingw64\bin\g++.exe",
        r"C:\msys64\clang64\bin\clang++.exe",
        r"C:\mingw64\bin\g++.exe",
        r"C:\MinGW\bin\g++.exe",
        r"C:\ProgramData\chocolatey\bin\g++.exe",
    ]
    return [p for p in patterns if Path(p).is_file()]


def _candidate_paths_msvc() -> List[str]:
    """Glob for cl.exe under Visual Studio install roots."""
    roots = [
        r"C:\Program Files\Microsoft Visual Studio",
        r"C:\Program Files (x86)\Microsoft Visual Studio",
    ]
    found: List[str] = []
    for root in roots:
        # e.g. .../2022/Community/VC/Tools/MSVC/<ver>/bin/Hostx64/x64/cl.exe
        pattern = os.path.join(
            root, "*", "*", "VC", "Tools", "MSVC", "*", "bin", "Host*", "*", "cl.exe"
        )
        found.extend(glob.glob(pattern))
    return found


def _family_for(name: str) -> str:
    base = Path(name).name.lower()
    if base in ("cl", "cl.exe"):
        return FAMILY_MSVC
    return FAMILY_GCC


def detect_toolchain(override: Optional[str] = None) -> Toolchain:
    """Resolve a usable :class:`Toolchain` or raise :class:`ToolchainError`.

    Resolution order:
      1. ``override`` argument or ``CPPLINGS_CXX`` env var (a name on PATH or a
         full path).
      2. ``g++`` then ``clang++`` on PATH.
      3. ``cl`` on PATH.
      4. Known install locations for the GCC family, then MSVC.
    """
    override = override or os.environ.get("CPPLINGS_CXX")
    if override:
        resolved = shutil.which(override) or (override if Path(override).is_file() else None)
        if not resolved:
            raise ToolchainError(
                f"CPPLINGS_CXX is set to '{override}' but no such compiler was found."
            )
        family = _family_for(resolved)
        return Toolchain(path=resolved, family=family, name=Path(resolved).name)

    for name in ("g++", "clang++"):
        resolved = shutil.which(name)
        if resolved:
            return Toolchain(path=resolved, family=FAMILY_GCC, name=name)

    cl = shutil.which("cl")
    if cl:
        return Toolchain(path=cl, family=FAMILY_MSVC, name="cl")

    for path in _candidate_paths_gcc():
        return Toolchain(path=path, family=FAMILY_GCC, name=Path(path).name)

    for path in _candidate_paths_msvc():
        return Toolchain(path=path, family=FAMILY_MSVC, name="cl")

    raise ToolchainError(
        "No C++ compiler found. Install one of g++, clang++, or MSVC (cl.exe), "
        "or set CPPLINGS_CXX to the path of your compiler.\n"
        "  - Windows: install MSYS2 (https://www.msys2.org) then `pacman -S mingw-w64-ucrt-x86_64-gcc`,\n"
        "    or the Visual Studio Build Tools.\n"
        "  - macOS: `xcode-select --install`.\n"
        "  - Linux: `sudo apt install g++` (or your distro's equivalent)."
    )
