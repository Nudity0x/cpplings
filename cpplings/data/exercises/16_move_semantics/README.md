# Move Semantics

Copying a big object (a vector with a million elements, say) is expensive when the
source is about to be thrown away anyway. Move semantics let you *transfer*
ownership of an object's resources instead of duplicating them — cheap, and often
free.

An rvalue reference `T&&` binds to temporaries and other objects you're willing to
gut. `std::move` doesn't move anything itself; it casts an lvalue to an rvalue so
a move constructor or move assignment can take over its guts, leaving the source
in a valid-but-unspecified state. Understanding move is key to understanding why
modern C++ can return large objects by value without a performance penalty, and
it underpins types like `std::unique_ptr` that can't be copied at all.

## Further information

- [`std::move`](https://en.cppreference.com/w/cpp/utility/move)
- [Value categories](https://en.cppreference.com/w/cpp/language/value_category)
- [Introduction to move semantics](https://www.learncpp.com/cpp-tutorial/introduction-to-stdmove/)
