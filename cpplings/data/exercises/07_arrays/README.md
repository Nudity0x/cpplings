# Arrays

An array is a fixed-size, contiguous block of elements of the same type. C++
gives you two flavors: the built-in C array (`int a[5]`) inherited from C, and
`std::array<int, 5>` from `<array>`, which is a thin, safer wrapper that knows
its own size and works with the standard algorithms.

Indexing is zero-based, and C++ does **no** bounds checking on `a[i]` — reading or
writing past the end is undefined behavior, one of the language's sharpest edges.
Built-in arrays also "decay" to a pointer when passed to a function, losing their
size, which is a big reason to prefer `std::array` (or `std::vector` when the size
isn't fixed).

## Further information

- [`std::array`](https://en.cppreference.com/w/cpp/container/array)
- [C-style arrays](https://en.cppreference.com/w/cpp/language/array)
- [Introduction to `std::array`](https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/)
