# Pointers

A pointer holds the memory address of another object. `int* p = &x;` makes `p`
point at `x`; `*p` dereferences it to read or write the pointed-to value. Pointers
are what make dynamic memory, linked structures, and C interop possible — and
they're where a lot of C++'s footguns live.

A pointer can be null (`nullptr`), meaning it points at nothing; dereferencing a
null or dangling pointer is undefined behavior. Prefer `nullptr` over the old `0`
or `NULL`. This section is about raw pointers so you understand the machinery,
but in real code you'll usually reach for references (next section) or smart
pointers (later) to manage lifetime safely.

## Further information

- [Pointer declarations](https://en.cppreference.com/w/cpp/language/pointer)
- [`nullptr`](https://en.cppreference.com/w/cpp/language/nullptr)
- [Introduction to pointers](https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/)
