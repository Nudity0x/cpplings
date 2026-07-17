# Conditionals

Conditionals let a program choose what to do. `if` / `else if` / `else` run a
branch based on a boolean condition, and `switch` dispatches on the value of an
integer or enum.

Watch the details C++ cares about. The condition in an `if` must be (or convert
to) `bool` — and because non-zero values are "truthy", `if (x = 5)` compiles but
assigns instead of comparing. In a `switch`, each `case` falls through to the
next unless you `break`, which is occasionally useful and frequently a bug.
Modern C++ also lets you declare a variable right inside the condition, scoping
it to just that branch.

## Further information

- [`if` statement](https://en.cppreference.com/w/cpp/language/if)
- [`switch` statement](https://en.cppreference.com/w/cpp/language/switch)
- [If statements and blocks](https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/)
