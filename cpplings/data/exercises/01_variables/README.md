# Variables

C++ is statically typed: every variable has a type fixed at compile time, and
you must declare that type before you can use the variable. `int x = 42;` says
"x is an int, and its value is 42". Leave off the type and the compiler has no
idea what you mean.

Variables are mutable by default. Add `const` and the compiler will stop you
from changing a value after it's set — a cheap, powerful way to state intent and
catch bugs. You'll also meet `auto`, which asks the compiler to deduce the type
from the initializer, and the difference between initializing a variable and
merely declaring it.

## Further information

- [Declaring variables](https://en.cppreference.com/w/cpp/language/declarations)
- [`const` type qualifier](https://en.cppreference.com/w/cpp/language/cv)
- [Placeholder type `auto`](https://en.cppreference.com/w/cpp/language/auto)
- [Variables and fundamental types](https://www.learncpp.com/cpp-tutorial/introduction-to-fundamental-data-types/)
