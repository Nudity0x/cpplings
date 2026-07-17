# Optional & Variant

C++17 added vocabulary types that make "maybe" and "one of several" explicit in
the type system. `std::optional<T>` (from `<optional>`) holds either a `T` or
nothing — perfect for a function that might not have a result, instead of magic
sentinel values or output parameters. Check it with `if (opt)` and read it with
`*opt` or `opt.value()`.

`std::variant<A, B, C>` (from `<variant>`) is a type-safe union: it holds exactly
one of its listed types at a time and always knows which. Query it with
`std::holds_alternative<T>`, pull a value out with `std::get<T>`, and handle every
case at once with `std::visit`. Together these types replace whole categories of
error-prone pointer and union tricks with something the compiler checks.

## Further information

- [`std::optional`](https://en.cppreference.com/w/cpp/utility/optional)
- [`std::variant`](https://en.cppreference.com/w/cpp/utility/variant)
- [`std::visit`](https://en.cppreference.com/w/cpp/utility/variant/visit)
