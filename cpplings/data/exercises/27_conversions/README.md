# Conversions

C++ converts between types constantly — some implicitly, some only when you ask.
Implicit conversions happen silently (an `int` promoted to `double`), which is
convenient but can lose data or surprise you. Explicit conversions use the named
cast operators, and each says exactly what kind of conversion you intend.

`static_cast` handles well-defined conversions like numeric types or up/down a
class hierarchy you know is safe. `dynamic_cast` does a checked downcast on
polymorphic types, returning null (or throwing) if the object isn't actually the
target type. `const_cast` adds or removes `const`, and `reinterpret_cast`
reinterprets the bits — powerful and dangerous. Prefer the narrow, named casts
over the C-style `(T)x`, because they document intent and let the compiler catch
mistakes.

## Further information

- [`static_cast`](https://en.cppreference.com/w/cpp/language/static_cast)
- [`dynamic_cast`](https://en.cppreference.com/w/cpp/language/dynamic_cast)
- [Explicit type conversion](https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/)
