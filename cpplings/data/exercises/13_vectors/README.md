# Vectors

`std::vector` from `<vector>` is the workhorse container of C++: a dynamic array
that grows and shrinks at runtime while keeping its elements contiguous in
memory. If you're unsure which container to use, the answer is almost always
`std::vector`.

Add elements with `.push_back()` or `.emplace_back()`, read them with `[]` or the
bounds-checked `.at()`, and ask for `.size()` or `.empty()`. A vector manages its
own memory, so it cleans up automatically when it goes out of scope. It grows by
reallocating to a bigger block when it runs out of capacity — `.reserve()` up
front avoids repeated reallocations when you know roughly how many elements
you'll add. Note `.size()` returns an unsigned type, which can surprise you in
comparisons with signed ints.

## Further information

- [`std::vector`](https://en.cppreference.com/w/cpp/container/vector)
- [Introduction to `std::vector`](https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/)
- [`push_back` vs `emplace_back`](https://en.cppreference.com/w/cpp/container/vector/emplace_back)
