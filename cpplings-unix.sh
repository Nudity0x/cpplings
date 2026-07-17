#!/usr/bin/env bash
# ============================================================================
#  cpplings launcher for macOS / Linux — double-click it, or run ./cpplings-unix.sh
#
#  Runs cpplings straight from this source checkout (no install needed), sets
#  up the exercises the first time, and opens the watch TUI. Compiler detection
#  is handled by cpplings itself.
# ============================================================================

set -euo pipefail

# Work from the directory this script lives in, whatever the CWD was.
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# Find a Python interpreter.
PYTHON=""
if command -v python3 >/dev/null 2>&1; then
    PYTHON=python3
elif command -v python >/dev/null 2>&1; then
    PYTHON=python
else
    echo "Python was not found on your PATH."
    echo "Install Python 3.9+ (e.g. 'sudo apt install python3' or 'brew install python') and try again."
    read -r -p "Press Enter to close..." _
    exit 1
fi

# Run cpplings from this checkout so no 'pip install' is required.
export PYTHONPATH="$SCRIPT_DIR:${PYTHONPATH:-}"

# First run: lay down the exercises workspace next to this script.
if [ ! -f "$SCRIPT_DIR/workspace/info.toml" ]; then
    echo "Setting up your cpplings exercises for the first time..."
    "$PYTHON" -m cpplings init "$SCRIPT_DIR/workspace"
    echo
fi

cd "$SCRIPT_DIR/workspace"
"$PYTHON" -m cpplings watch
