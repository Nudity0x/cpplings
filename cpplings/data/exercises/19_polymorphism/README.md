# Polymorphism

Polymorphism lets a call through a base-class pointer or reference run the
*derived* class's version of a function, chosen at runtime. Mark a member function
`virtual` in the base class and override it in the derived class, and
`animal->speak()` calls the right `speak()` for whatever the object actually is.

Always tag overrides with the `override` keyword — the compiler then verifies you
really are overriding something, catching typos and signature mismatches. A pure
virtual function (`virtual void draw() = 0;`) makes the class abstract: it can't be
instantiated and demands that derived classes implement it, which is how C++
expresses interfaces. And remember: any base class used polymorphically needs a
`virtual` destructor.

## Further information

- [`virtual` functions](https://en.cppreference.com/w/cpp/language/virtual)
- [`override` specifier](https://en.cppreference.com/w/cpp/language/override)
- [Virtual functions and polymorphism](https://www.learncpp.com/cpp-tutorial/virtual-functions/)
