# Classes

A class bundles data (member variables) with the behavior that operates on it
(member functions), and controls access with `public`, `private`, and
`protected`. This is the heart of C++'s object-oriented side: keep the internal
state private and expose a clean public interface.

Constructors initialize an object when it's created; the destructor runs when it
goes out of scope, which is where C++'s RAII idiom cleans up resources
automatically. Prefer the member initializer list (`Foo() : x_(0) {}`) over
assigning in the constructor body. As you go you'll meet `this`, const member
functions that promise not to mutate the object, and static members shared across
all instances.

## Further information

- [Classes](https://en.cppreference.com/w/cpp/language/classes)
- [Constructors](https://en.cppreference.com/w/cpp/language/constructor)
- [Intro to classes](https://www.learncpp.com/cpp-tutorial/introduction-to-classes/)
