# Lambdas

A lambda is an anonymous function you can define inline, right where you need it:
`[](int a, int b) { return a + b; }`. They're the natural way to pass behavior to
standard algorithms — a custom comparator for `std::sort`, a predicate for
`std::find_if`, an action for `std::for_each`.

The `[]` is the capture list: it controls which surrounding variables the lambda
can see. `[x]` captures a copy, `[&x]` captures by reference, `[=]` and `[&]`
capture everything by copy or reference respectively. Prefer capturing exactly
what you need. A lambda that captures nothing converts to a plain function
pointer; one that captures state is its own unique type, usually stored in
`auto` or `std::function`. Since C++14 you can use `auto` parameters for generic
lambdas.

## Further information

- [Lambda expressions](https://en.cppreference.com/w/cpp/language/lambda)
- [Introduction to lambdas](https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/)
- [Lambda captures](https://www.learncpp.com/cpp-tutorial/lambda-captures/)
