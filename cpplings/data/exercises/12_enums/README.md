# Enums

An enumeration is a type with a fixed set of named values — perfect for things
like `Color::Red` or `State::Running` instead of magic numbers. Modern C++
strongly prefers the *scoped* enum, `enum class Color { Red, Green, Blue };`,
whose values are namespaced (`Color::Red`) and don't implicitly convert to `int`.

That lack of implicit conversion is the whole point: it stops you from
accidentally comparing a `Color` to a `Direction` or doing arithmetic that makes
no sense. Plain unscoped `enum` still exists and does convert to int, which is
occasionally handy but more error-prone. You can set explicit underlying values
and choose the underlying integer type when you need to.

## Further information

- [Enumerations](https://en.cppreference.com/w/cpp/language/enum)
- [Scoped enumerations (`enum class`)](https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/)
- [Unscoped enumerations](https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/)
