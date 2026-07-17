# Templates

Templates let you write code once that works for many types. `template <typename T>
T max(T a, T b)` defines a family of functions; the compiler stamps out a concrete
version for each type you actually use. This is how `std::vector<int>` and
`std::vector<std::string>` come from a single definition.

Both functions and classes can be templated. The type is usually deduced from the
arguments, so you rarely spell it out. Templates are resolved entirely at compile
time — there's no runtime cost — but that also means template errors surface at
compile time and can be verbose. You'll see type parameters, non-type parameters
(like a size), and the way template code must generally live in headers.

## Further information

- [Templates](https://en.cppreference.com/w/cpp/language/templates)
- [Function templates](https://en.cppreference.com/w/cpp/language/function_template)
- [Introduction to function templates](https://www.learncpp.com/cpp-tutorial/function-templates/)
