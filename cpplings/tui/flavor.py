"""Entertainment content for the TUI: praise, nudges, trivia, and art.

Kept separate from ``app.py`` so the app logic stays readable and the fun
copy is easy to extend. Everything here is pure data + small helpers with no
Textual dependency, so it's trivially testable.
"""

from __future__ import annotations

import random
from typing import List, Optional

# Shown (as a toast) when an exercise is solved. Kept short and varied so the
# reward doesn't get stale over 90+ exercises.
PRAISE: List[str] = [
    "Nailed it.",
    "Clean solve.",
    "That compiles beautifully.",
    "Green across the board.",
    "Textbook.",
    "You made that look easy.",
    "Ship it.",
    "No warnings, no worries.",
    "The compiler approves.",
    "Segfaults fear you.",
    "RAII would be proud.",
    "Zero-cost abstraction, maximum style.",
    "That's the good stuff.",
    "Undefined behavior: not today.",
    "Crisp.",
]

# Shown when the current exercise still fails. Encouraging, never scolding —
# the goal is to keep momentum, not to nag.
ENCOURAGEMENT: List[str] = [
    "Almost — read the error top to bottom.",
    "Compilers are picky, not personal.",
    "You're one fix away.",
    "Every C++ dev has seen this error. Keep going.",
    "Small change, big difference. You've got it.",
    "Read the first error only — the rest are often noise.",
    "Save when ready; I'll recheck instantly.",
    "Press h if you want a nudge.",
]

# Rotating "did you know" trivia, shown beneath a failing exercise so there's
# always something to read while you think.
TIPS: List[str] = [
    "std::endl flushes the stream; '\\n' usually doesn't. Prefer '\\n' in loops.",
    "Prefer std::make_unique over new — it's exception-safe and never leaks.",
    "A const reference (const T&) avoids a copy without allowing changes.",
    "auto deduces the type from the initializer — great for long iterator types.",
    "Range-based for (for (auto& x : v)) beats index loops for readability.",
    "std::vector grows automatically; reserve() avoids repeated reallocations.",
    "Rule of Zero: if you don't manage a resource, don't write special members.",
    "A moved-from object is valid but unspecified — safe to destroy or reassign.",
    "Mark overriding methods with 'override' so the compiler catches typos.",
    "Polymorphic base classes need a virtual destructor to avoid leaks.",
    "std::optional<T> beats magic sentinels like -1 for 'maybe no value'.",
    "Pass small types (int, double) by value; pass big ones by const reference.",
    "size() returns an unsigned type — watch out comparing it to signed ints.",
    "Uniform init with {} rejects narrowing conversions that () allows.",
    "std::string::find returns std::string::npos when nothing matches.",
    "Lambdas capturing by [&] hold references — don't outlive what they capture.",
    "constexpr lets the compiler compute values before the program even runs.",
    "std::array<T, N> is a stack array that knows its own size.",
    "Prefer nullptr over NULL or 0 for pointers — it has a real pointer type.",
    "emplace_back constructs in place; push_back may copy or move.",
]

# Milestone banners, keyed by the percentage crossed. Shown as a toast when a
# solve pushes total completion past a threshold.
_MILESTONES = [
    (25, "Quarter done! The fundamentals are yours."),
    (50, "Halfway! You're past the hump."),
    (75, "Three quarters! The finish line is in sight."),
]

# Encouraging one-liners tied to the running session streak.
_STREAK_LINES = {
    3: "3 in a row!",
    5: "5-solve streak — on fire.",
    10: "10 straight. Unstoppable.",
    15: "15-solve streak. Are you even human?",
}

# Shown once when every exercise is complete.
COMPLETION_ART = r"""
   ___                      _         _
  / __\ __  _ __   __ _ _ __ __ _  __| |___
 / /  / _ \| '_ \ / _` | '__/ _` |/ _` / __|
/ /__| (_) | | | | (_| | | | (_| | (_| \__ \
\____/\___/|_| |_|\__, |_|  \__,_|\__,_|___/
                  |___/

        You finished every cpplings exercise.
     From "hello" to templates, moves, and the STL.
                  That's the whole core.
"""


def random_praise() -> str:
    return random.choice(PRAISE)


def random_encouragement() -> str:
    return random.choice(ENCOURAGEMENT)


def random_tip() -> str:
    return random.choice(TIPS)


def milestone_message(prev_done: int, now_done: int, total: int) -> Optional[str]:
    """Return a milestone banner if this solve crossed a percentage threshold.

    ``prev_done``/``now_done`` are done-counts before and after the solve.
    """
    if total <= 0 or now_done <= prev_done:
        return None
    prev_pct = 100 * prev_done / total
    now_pct = 100 * now_done / total
    for threshold, message in _MILESTONES:
        if prev_pct < threshold <= now_pct:
            return message
    return None


def streak_message(streak: int) -> Optional[str]:
    """Return a celebratory line if the streak just hit a notable number."""
    return _STREAK_LINES.get(streak)
