# Iterators

Iterators are the glue between containers and algorithms. An iterator is a
generalized pointer: it refers to an element and knows how to advance to the next
one. Every standard container exposes `begin()` (first element) and `end()` (one
past the last), and that pair defines a range algorithms can walk.

Dereference an iterator with `*it` to get the element, advance with `++it`, and
compare against `end()` to know when you're done — exactly the pattern a
range-based `for` loop hides for you. Different containers offer different
iterator strengths: a vector's iterators support random jumps (`it + 5`), while a
list's only step one at a time. Beware invalidation: modifying a container can
leave existing iterators dangling.

## Further information

- [Iterator library](https://en.cppreference.com/w/cpp/iterator)
- [Introduction to iterators](https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/)
- [`begin` / `end`](https://en.cppreference.com/w/cpp/iterator/begin)
