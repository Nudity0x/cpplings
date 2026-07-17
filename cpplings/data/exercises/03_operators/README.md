# Operators

Operators are the verbs of C++: arithmetic (`+ - * / %`), comparison
(`== != < >`), logical (`&& || !`), and assignment (`= += ++`). Most behave the
way you'd expect from maths, but a few C++ specifics bite newcomers.

Integer division truncates: `7 / 2` is `3`, not `3.5` — you need a floating-point
operand to get a fractional result. The modulo operator `%` gives the remainder.
Logical `&&` and `||` short-circuit: the right side isn't evaluated if the left
already decides the answer. And pre-increment (`++i`) versus post-increment
(`i++`) differ in what value the expression yields, which matters inside larger
expressions.

## Further information

- [Operator precedence](https://en.cppreference.com/w/cpp/language/operator_precedence)
- [Arithmetic operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic)
- [Increment/decrement and side effects](https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/)
