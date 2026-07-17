# Structs

A `struct` groups related data under one type. `struct Point { int x; int y; };`
defines a new type whose members you reach with the dot operator: `p.x`. Structs
are the foundation for modeling real-world things as values you can pass around,
return, and store in containers.

In C++ a `struct` is really just a `class` whose members default to `public`, so
structs can also have constructors and member functions — but by convention they
stay simple, plain-data aggregates. You can brace-initialize them
(`Point p{1, 2};`), and you'll meet nested structs and arrays of structs as you
build up more interesting data.

## Further information

- [Class/struct types](https://en.cppreference.com/w/cpp/language/class)
- [Aggregate initialization](https://en.cppreference.com/w/cpp/language/aggregate_initialization)
- [Introduction to structs](https://www.learncpp.com/cpp-tutorial/introduction-to-structs-members-and-member-selection/)
