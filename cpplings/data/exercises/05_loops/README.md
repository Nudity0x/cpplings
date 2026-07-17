# Loops

C++ has several ways to repeat work. The classic `for (init; condition; update)`
loop is ideal when you know the bounds; `while` loops until a condition goes
false; `do...while` runs the body at least once before checking. `break` leaves a
loop early and `continue` skips to the next iteration.

The range-based `for` loop — `for (auto x : container)` — is the modern
workhorse for walking a collection without index bookkeeping. Take the element by
value to copy it, by `&` to modify it in place, or by `const&` to read it cheaply
without copying. Off-by-one errors on the loop bounds are the most common bug
here, so mind your `<` versus `<=`.

## Further information

- [`for` loop](https://en.cppreference.com/w/cpp/language/for)
- [Range-based `for` loop](https://en.cppreference.com/w/cpp/language/range-for)
- [Intro to loops and while statements](https://www.learncpp.com/cpp-tutorial/intro-to-loops-and-while-statements/)
