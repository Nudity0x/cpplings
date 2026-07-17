# Operator Overloading

C++ lets your own types use built-in operators. Define `operator+` for a `Vector2`
and `a + b` just works; define `operator==` and you can compare instances; define
`operator<<` and your type prints with `std::cout`. Used well, this makes custom
types feel like first-class citizens of the language.

Some operators are best as member functions (like compound assignment `+=`),
others as free functions (like stream `<<`, whose left operand is the stream, not
your type). Overload to *match* the conventional meaning — `+` should combine, `==`
should compare — never to do something surprising. Since C++20 the "spaceship"
operator `<=>` can generate all the comparison operators from one definition.

## Further information

- [Operator overloading](https://en.cppreference.com/w/cpp/language/operators)
- [Introduction to operator overloading](https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/)
- [Overloading `<<` for output](https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/)
