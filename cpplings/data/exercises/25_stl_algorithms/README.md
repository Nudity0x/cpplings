# STL Algorithms

The `<algorithm>` header is one of C++'s best-kept productivity secrets: dozens of
tested, optimized functions that operate on ranges so you rarely have to write a
raw loop. `std::sort`, `std::find`, `std::count_if`, `std::transform`,
`std::accumulate` (from `<numeric>`), and many more.

Algorithms work on iterator ranges — usually `begin()` to `end()` — and most take
a lambda to customize what they do: a comparator for `sort`, a predicate for
`find_if`, a transformation for `transform`. Preferring these named algorithms
over hand-written loops makes intent obvious and bugs rarer. This is the core of
"write what you mean" C++; the C++20 ranges library makes it even cleaner.

## Further information

- [Algorithms library](https://en.cppreference.com/w/cpp/algorithm)
- [`std::sort`](https://en.cppreference.com/w/cpp/algorithm/sort)
- [`std::transform`](https://en.cppreference.com/w/cpp/algorithm/transform)
