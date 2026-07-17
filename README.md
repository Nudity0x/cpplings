# cpplings

Greetings and welcome to **cpplings**. This project contains small exercises to
get you used to reading and writing C++ code. This includes fixing compiler
errors, making tests pass, and getting comfortable with the language core all
the way through moves, smart pointers, polymorphism, and the STL.

cpplings is a loving port of [**Rustlings**](https://github.com/rust-lang/rustlings)
to C++. If you have ever done Rustlings, everything here will feel like home —
because it is. The workflow, the watch loop, the `// I AM NOT DONE` marker, the
hints, the whole "fix one tiny broken program at a time" idea: all of it comes
straight from Rustlings. cpplings would not exist without it. See
[Credit & thanks](#credit--thanks) below — it is the most important section in
this file.

---

## Getting started

### 1. Install a C++ compiler

cpplings compiles real C++, so you need a C++17 toolchain. Any one of these works:

- **Linux** — `sudo apt install g++` (or your distro's equivalent)
- **macOS** — `xcode-select --install`
- **Windows** — [MSYS2](https://www.msys2.org) then
  `pacman -S mingw-w64-ucrt-x86_64-gcc`, or the Visual Studio Build Tools
  (`cl.exe`)

### 2. Install cpplings

cpplings itself is a small Python program. Install it straight from the
repository with `pipx` (recommended) or `pip`:

```bash
pipx install git+https://github.com/Nudity0x/cpplings.git
# or, from a local clone:
#   git clone https://github.com/Nudity0x/cpplings.git
#   cd cpplings && pipx install .
```

### 3. Initialize the exercises

```bash
cpplings init              # copies the exercises into ./cpplings
cd cpplings
```

### 4. Start the watch loop

```bash
cpplings watch             # or just: cpplings
```

That's it. Open the first exercise in your editor, read the `// TODO`, make it
compile and pass, then delete the `// I AM NOT DONE` line and save. cpplings
notices the save, re-checks instantly, and moves you along.

---

## Doing the exercises

The exercises are ordered by topic and live in the `exercises/` directory. For
every exercise there is a matching reference solution in `solutions/` — try not
to peek until you've given it a real shot.

Each exercise is a single `.cpp` file that is **deliberately broken**. Your job
is to make it work. An exercise is considered done when all three are true:

1. It **compiles** with your C++17 toolchain.
2. It **runs and passes** — exercises with tests use the bundled
   `cpplings_test.hpp` assertion header, so there is **no test framework to
   install**.
3. You have **removed the `// I AM NOT DONE`** comment.

The marker is there on purpose (a Rustlings idea): it stops you from blowing
past an exercise that happens to already compile, and lets you keep tinkering
after you've solved it before moving on.

If you get stuck, ask for a hint — every exercise has one.

---

## The watch TUI

`cpplings watch` gives you a full-screen terminal UI that re-checks on every
save. An inline, syntax-highlighted **editor** opens on the current exercise so
you can fix it right there; a pane above shows your program's **output** (or the
compiler's errors).

Because the editor is focused by default, the actions use `ctrl` combos so they
work while you're typing. Each also has a bare-letter shortcut for when the
editor is closed:

| Key | Action |
| --- | --- |
| `ctrl+s` | **save** the editor buffer (rechecks automatically) |
| `ctrl+n` / `n` | go to the **next** exercise (once the current one is done) |
| `ctrl+r` / `r` | **re-run** the current exercise now |
| `ctrl+g` / `h` | toggle the **hint** |
| `ctrl+b` / `m` | toggle the section **README** (concept explainer) |
| `ctrl+l` / `l` | toggle the **list** of all exercises (navigable) |
| `ctrl+o` / `e` | open the current exercise in your external **editor**/IDE |
| `c` | toggle the inline editor |
| `x` | **reset** the current exercise to its original broken state |
| `ctrl+q` / `q` | **quit** |
| `escape` | close whichever overlay is open |

Fix the `// TODO`, delete the `// I AM NOT DONE` line, and press `ctrl+s` —
cpplings rechecks instantly. In the **list** overlay, arrow to any exercise and
press `Enter` to jump to it, or `x` to reset it. Prefer your own editor? Press
`ctrl+o` to open the file externally; cpplings still rechecks on every save.

Checks run on a background thread so the UI never freezes while the compiler
works, and there's a bit of fun along the way — praise on a solve, streaks,
milestones, and rotating C++ tips while you think.

---

## Commands

You don't need the TUI for everything. cpplings also works one-shot from the
shell:

| Command | What it does |
| --- | --- |
| `cpplings init [dir]` | Copy the exercises into a working directory (default `./cpplings`). |
| `cpplings watch` | Auto-check exercises as you edit them (the default). |
| `cpplings run [name]` | Check one exercise once and print the result. |
| `cpplings list` | Show every exercise and your progress. |
| `cpplings hint [name]` | Print the hint for an exercise. |
| `cpplings readme [name]` | Print the section README (concept explainer) for an exercise. |
| `cpplings reset [name]` | Restore an exercise to its original broken state. |
| `cpplings verify` | (dev) Compile and run every reference solution. |

If `[name]` is omitted, the command acts on the current (next pending) exercise.

---

## Choosing a compiler

cpplings auto-detects a toolchain in this order:

1. The `CPPLINGS_CXX` environment variable (a compiler name on `PATH`, or a full
   path).
2. `g++`, then `clang++`, then `cl.exe` on your `PATH`.
3. Common install locations (MSYS2, Visual Studio) — handy on Windows where the
   compiler often isn't on `PATH`.

Force a specific compiler any time:

```bash
CPPLINGS_CXX=clang++ cpplings watch
```

---

## Curriculum

cpplings starts at the language core — the kind of ground
[learncpp.com](https://www.learncpp.com) covers — and builds up to the modern
C++ that makes the language worth learning. Exercises are grouped into sections:

| # | Section | Topic |
| --- | --- | --- |
| 00 | `intro` | the workflow itself |
| 01 | `variables` | declarations, types, `const`, `auto` |
| 02 | `io` | streams and formatted output |
| 03 | `operators` | arithmetic, comparison, logic |
| 04 | `conditionals` | `if`/`else`, `switch` |
| 05 | `loops` | `for`, `while`, range-based `for` |
| 06 | `functions` | parameters, returns, overloading |
| 07 | `arrays` | fixed arrays and indexing |
| 08 | `strings` | `std::string` basics |
| 09 | `pointers` | addresses, dereferencing, `nullptr` |
| 10 | `references` | binding and pass-by-reference |
| 11 | `structs` | aggregate types |
| 12 | `enums` | plain and scoped enums |
| 13 | `vectors` | `std::vector` |
| 14 | `classes` | encapsulation, constructors, methods |
| 15 | `templates` | generic functions and types |
| 16 | `move_semantics` | `std::move`, move constructors |
| 17 | `smart_pointers` | `unique_ptr`, `shared_ptr` |
| 18 | `inheritance` | base/derived, constructor chaining |
| 19 | `polymorphism` | `virtual`, `override`, virtual destructors |
| 20 | `operator_overloading` | `operator+`, `==`, `[]` |
| 21 | `exceptions` | `throw`/`catch`, custom types |
| 22 | `optional_variant` | `std::optional`, `std::variant` |
| 23 | `lambdas` | closures and captures |
| 24 | `stl_containers` | `map`, `set`, `pair` |
| 25 | `stl_algorithms` | `sort`, `count`, `accumulate` |
| 26 | `iterators` | `begin`/`end`, reverse, `distance` |
| 27 | `conversions` | `static_cast`, converting constructors |
| 28 | `quizzes` | cumulative, multi-topic challenges |

---

## Uninstalling

```bash
pipx uninstall cpplings    # or: pip uninstall cpplings
```

Your progress lives in the `.cpplings-state.txt` file inside your working
directory, so deleting that directory removes everything cpplings created.

---

## Credit & thanks

**cpplings stands entirely on the shoulders of [Rustlings](https://github.com/rust-lang/rustlings).**

Rustlings is the original and the inspiration for every part of this project —
the fix-the-broken-program format, the auto-checking watch loop, the
`// I AM NOT DONE` marker, on-demand hints, the exercise/solution layout, the
section ordering, and the whole gentle on-ramp philosophy. cpplings is a port of
that idea to C++, and any praise for the *concept* belongs to Rustlings, not to
this repo.

Rustlings is created and maintained by **Mo Bitar**, **Liv**, and
**Carol (Nichols || Goulding)**, along with its many wonderful contributors, and
is part of the [Rust Programming Language](https://github.com/rust-lang)
organization. It is licensed under the MIT license.

If you are learning Rust, or even if you aren't, go star Rustlings and do the
original — it is a genuinely delightful piece of teaching software:

👉 **https://github.com/rust-lang/rustlings**

Thank you, Rustlings team. cpplings is a tribute. 🧡

---

## Requirements

- Python 3.9+
- A C++17 compiler (`g++`, `clang++`, or MSVC `cl.exe`)

## License

The cpplings tooling and exercises are provided under the MIT license, the same
license Rustlings uses. See [`LICENSE`](LICENSE).
