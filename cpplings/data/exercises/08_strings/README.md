# Strings

C++ text lives in `std::string` (from `<string>`), a growable, owning sequence of
characters. It handles its own memory, so you can append, concatenate with `+`,
compare with `==`, and query its `.size()` without the manual bookkeeping that
C-style `char*` strings demand.

Reach for member functions like `.substr()`, `.find()`, `.at()`, and `.append()`
to slice and search. `std::string_view` (C++17) is a lightweight, non-owning
window onto existing character data — great for read-only parameters because it
avoids a copy. Remember that indexing with `[]` isn't bounds-checked, while
`.at()` throws if you go out of range.

## Further information

- [`std::string`](https://en.cppreference.com/w/cpp/string/basic_string)
- [`std::string_view`](https://en.cppreference.com/w/cpp/string/basic_string_view)
- [Introduction to `std::string`](https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/)
