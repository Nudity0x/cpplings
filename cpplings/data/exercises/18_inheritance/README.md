# Inheritance

Inheritance lets one class build on another. `class Dog : public Animal` says a
`Dog` *is an* `Animal` — it gets `Animal`'s members and can add or specialize its
own. This models "is-a" relationships and lets you share common behavior across a
family of types.

The base class initializes its part of the object first (call its constructor in
your member initializer list), then the derived class adds its own. Use `public`
inheritance for genuine is-a relationships; `protected` members are visible to
derived classes but not the outside world. A crucial detail: if you'll delete
derived objects through a base pointer, the base class needs a `virtual`
destructor — which leads straight into the next section, polymorphism.

## Further information

- [Derived classes](https://en.cppreference.com/w/cpp/language/derived_class)
- [Introduction to inheritance](https://www.learncpp.com/cpp-tutorial/introduction-to-inheritance/)
- [Order of construction](https://www.learncpp.com/cpp-tutorial/order-of-construction-of-derived-classes/)
