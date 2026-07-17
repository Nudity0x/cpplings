# Functions

A function bundles a piece of behavior behind a name. In C++ you declare the
return type, the name, and a typed parameter list: `int add(int a, int b)`. A
function that returns nothing has return type `void`.

C++ passes arguments *by value* by default, meaning the function gets its own
copy — changes don't leak back to the caller. Pass by reference (`int&`) to let
the function modify the caller's variable, or by `const&` to avoid copying large
objects while still promising not to change them. You'll also see default
arguments, and function overloading, where several functions share a name but
differ in their parameters and the compiler picks the right one.

## Further information

- [Functions](https://en.cppreference.com/w/cpp/language/functions)
- [Overload resolution](https://en.cppreference.com/w/cpp/language/overload_resolution)
- [Introduction to functions](https://www.learncpp.com/cpp-tutorial/introduction-to-functions/)
