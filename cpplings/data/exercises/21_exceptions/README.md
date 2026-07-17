# Exceptions

Exceptions are C++'s mechanism for reporting errors that can't be handled where
they occur. You `throw` an exception object, the stack unwinds (running
destructors along the way, thanks to RAII), and the nearest matching `catch`
block handles it. This separates the error-handling path from the normal path.

Throw exception types from `<stdexcept>` like `std::runtime_error` or
`std::out_of_range`, and catch them by `const&` to avoid slicing and copying.
Order `catch` blocks from most-derived to most-general, since the first match
wins. Use exceptions for genuinely exceptional conditions, not routine control
flow, and lean on RAII so a thrown exception can't leak resources.

## Further information

- [Exceptions](https://en.cppreference.com/w/cpp/language/exceptions)
- [Standard exception types](https://en.cppreference.com/w/cpp/error/exception)
- [Basic exception handling](https://www.learncpp.com/cpp-tutorial/basic-exception-handling/)
