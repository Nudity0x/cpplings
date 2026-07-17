@echo off
REM ============================================================================
REM  cpplings launcher for Windows — just double-click this file.
REM
REM  It runs cpplings straight from this source checkout (no install needed),
REM  sets up the exercises the first time, and opens the watch TUI. Compiler
REM  detection (MSYS2 / Visual Studio) is handled by cpplings itself.
REM ============================================================================

setlocal

REM Work from the directory this script lives in, whatever the CWD was.
cd /d "%~dp0"

REM Find a Python interpreter: prefer the launcher `py`, fall back to `python`.
set "PYTHON="
where py >nul 2>&1 && set "PYTHON=py"
if not defined PYTHON where python >nul 2>&1 && set "PYTHON=python"

if not defined PYTHON (
    echo Python was not found on your PATH.
    echo Install Python 3.9+ from https://www.python.org/downloads/ and try again.
    echo.
    pause
    exit /b 1
)

REM Run cpplings from this checkout so no `pip install` is required.
set "PYTHONPATH=%~dp0;%PYTHONPATH%"

REM First run: lay down the exercises workspace next to this script.
if not exist "%~dp0workspace\info.toml" (
    echo Setting up your cpplings exercises for the first time...
    %PYTHON% -m cpplings init "%~dp0workspace"
    echo.
)

cd /d "%~dp0workspace"
%PYTHON% -m cpplings watch

REM If the TUI exited with an error, keep the window open so it can be read.
if errorlevel 1 (
    echo.
    echo cpplings exited with an error. See the message above.
    pause
)

endlocal
