# Smart Pointers

Smart pointers, from `<memory>`, manage dynamically allocated memory for you so
you never write a matching `delete` by hand. They apply RAII to raw pointers:
when the smart pointer goes out of scope, the memory is freed automatically. In
modern C++ you should almost never use raw `new`/`delete` directly.

`std::unique_ptr` models exclusive ownership — it can't be copied, only moved, and
frees its object when destroyed. Create one with `std::make_unique`.
`std::shared_ptr` models shared ownership via reference counting: the object lives
until the last `shared_ptr` to it is gone. `std::weak_ptr` observes a
`shared_ptr` without keeping it alive, which is how you break reference cycles.
Reach for `unique_ptr` by default and `shared_ptr` only when ownership is
genuinely shared.

## Further information

- [`std::unique_ptr`](https://en.cppreference.com/w/cpp/memory/unique_ptr)
- [`std::shared_ptr`](https://en.cppreference.com/w/cpp/memory/shared_ptr)
- [Introduction to smart pointers](https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/)
