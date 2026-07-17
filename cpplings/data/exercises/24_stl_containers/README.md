# STL Containers

Beyond `std::vector`, the standard library ships a whole toolbox of containers,
each with different performance trade-offs. `std::map` and `std::set` keep
elements sorted (balanced trees, O(log n) lookup); their `unordered_` cousins use
hash tables for average O(1) lookup at the cost of ordering. `std::list` is a
doubly linked list, `std::deque` a double-ended queue.

Pick the container that matches your access pattern: `std::map<Key, Value>` for
key/value lookups, `std::set` for a collection of unique sorted items,
`std::unordered_map` when you need fast lookup and don't care about order. Learn
the shared vocabulary — `.insert()`, `.find()`, `.count()`, `.erase()`, iteration
with range-`for` — and you can move between containers easily.

## Further information

- [Containers library](https://en.cppreference.com/w/cpp/container)
- [`std::map`](https://en.cppreference.com/w/cpp/container/map)
- [`std::unordered_map`](https://en.cppreference.com/w/cpp/container/unordered_map)
