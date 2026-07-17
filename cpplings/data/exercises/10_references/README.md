# References

A reference is an alias for an existing object: `int& r = x;` makes `r` another
name for `x`, so touching `r` touches `x`. Unlike a pointer, a reference must be
bound when it's created, can never be rebound, and can't be null — which makes it
safer and cleaner for many jobs.

The everyday use is function parameters. Pass by `T&` when the function needs to
modify the caller's object, and by `const T&` to hand over a large object cheaply
while promising not to change it. That `const&` idiom is everywhere in idiomatic
C++ because it avoids a copy without giving up safety.

## Further information

- [Reference declarations](https://en.cppreference.com/w/cpp/language/reference)
- [Lvalue references](https://www.learncpp.com/cpp-tutorial/lvalue-references/)
- [Pass by reference](https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/)
