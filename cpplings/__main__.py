"""``cpplings`` entry point: argument parsing and command dispatch.

Running ``cpplings`` with no arguments starts the watch loop (the common case),
mirroring rustlings' default behavior.
"""

from __future__ import annotations

import argparse
import sys
from typing import List, Optional

from . import __version__
from . import cli


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="cpplings",
        description="Learn C++ by fixing small broken exercises. Rustlings, for C++.",
    )
    parser.add_argument(
        "--version", action="version", version=f"cpplings {__version__}"
    )
    sub = parser.add_subparsers(dest="command")

    p_init = sub.add_parser("init", help="set up the exercises in a new directory")
    p_init.add_argument(
        "target", nargs="?", help="destination directory (default: ./cpplings)"
    )

    sub.add_parser("watch", help="auto-check exercises as you edit them (default)")

    p_run = sub.add_parser("run", help="check one exercise once")
    p_run.add_argument("exercise", nargs="?", help="exercise name (default: current)")

    sub.add_parser("list", help="show all exercises and progress")

    p_hint = sub.add_parser("hint", help="show the hint for an exercise")
    p_hint.add_argument("exercise", nargs="?", help="exercise name (default: current)")

    p_reset = sub.add_parser("reset", help="restore an exercise to its original state")
    p_reset.add_argument("exercise", nargs="?", help="exercise name (default: current)")

    p_readme = sub.add_parser(
        "readme", help="show the section README for an exercise"
    )
    p_readme.add_argument(
        "exercise", nargs="?", help="exercise name (default: current)"
    )

    sub.add_parser("verify", help="(dev) compile and run every solution")

    return parser


def _run_watch() -> int:
    # Imported lazily so the CLI works even if Textual isn't installed for
    # non-TUI commands (e.g. `run`, `verify` in CI).
    from .tui.app import run_watch_app

    return run_watch_app()


def main(argv: Optional[List[str]] = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)

    command = args.command or "watch"

    if command == "init":
        return cli.cmd_init(args.target)
    if command == "watch":
        return _run_watch()
    if command == "run":
        return cli.cmd_run(args.exercise)
    if command == "list":
        return cli.cmd_list()
    if command == "hint":
        return cli.cmd_hint(args.exercise)
    if command == "reset":
        return cli.cmd_reset(args.exercise)
    if command == "readme":
        return cli.cmd_readme(args.exercise)
    if command == "verify":
        return cli.cmd_verify()

    parser.print_help()
    return 1


if __name__ == "__main__":
    sys.exit(main())
