"""Parsing of ``info.toml``, the manifest describing all exercises.

The manifest mirrors rustlings' ``info.toml``: a ``format_version``, optional
welcome/final messages, and an ordered list of exercises. Each exercise entry
carries its name, the section directory it lives in, whether it has tests, and
a hint shown on demand.

Exercise file paths are derived from ``dir`` + ``name`` so the manifest stays
terse and the on-disk layout is predictable::

    exercises/<dir>/<name>.cpp
    solutions/<dir>/<name>.cpp
"""

from __future__ import annotations

import sys
from dataclasses import dataclass
from pathlib import Path
from typing import List, Optional

if sys.version_info >= (3, 11):
    import tomllib
else:  # pragma: no cover - exercised only on older interpreters
    import tomli as tomllib

FORMAT_VERSION = 1


class InfoFileError(RuntimeError):
    """Raised when ``info.toml`` is missing, malformed, or empty."""


@dataclass(frozen=True)
class ExerciseInfo:
    """One exercise as declared in ``info.toml``."""

    name: str
    dir: str
    hint: str
    test: bool = True

    def rel_path(self) -> Path:
        """Path to the exercise source, relative to the working directory."""
        return Path("exercises") / self.dir / f"{self.name}.cpp"

    def solution_rel_path(self) -> Path:
        """Path to the reference solution, relative to the working directory."""
        return Path("solutions") / self.dir / f"{self.name}.cpp"

    def readme_rel_path(self) -> Path:
        """Path to the section README, relative to the working directory.

        READMEs are per-section, not per-exercise, so every exercise in a
        section shares one.
        """
        return Path("exercises") / self.dir / "README.md"


@dataclass(frozen=True)
class InfoFile:
    """The parsed contents of ``info.toml``."""

    format_version: int
    exercises: List[ExerciseInfo]
    welcome_message: Optional[str] = None
    final_message: Optional[str] = None

    @classmethod
    def load(cls, path: Path) -> "InfoFile":
        """Parse ``info.toml`` at ``path``."""
        if not path.is_file():
            raise InfoFileError(f"info.toml not found at {path}")

        try:
            with path.open("rb") as fh:
                data = tomllib.load(fh)
        except tomllib.TOMLDecodeError as exc:
            raise InfoFileError(f"Failed to parse {path}: {exc}") from exc

        raw_exercises = data.get("exercises")
        if not raw_exercises:
            raise InfoFileError(
                "There are no exercises yet! Add at least one exercise to info.toml."
            )

        exercises: List[ExerciseInfo] = []
        for i, entry in enumerate(raw_exercises):
            try:
                exercises.append(
                    ExerciseInfo(
                        name=entry["name"],
                        dir=entry["dir"],
                        hint=entry.get("hint", "").strip(),
                        test=entry.get("test", True),
                    )
                )
            except KeyError as exc:
                raise InfoFileError(
                    f"Exercise #{i} in info.toml is missing required key {exc}"
                ) from exc

        return cls(
            format_version=data.get("format_version", FORMAT_VERSION),
            exercises=exercises,
            welcome_message=data.get("welcome_message"),
            final_message=data.get("final_message"),
        )
