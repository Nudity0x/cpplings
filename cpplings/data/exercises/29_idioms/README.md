# Idioms

This final section pulls together the patterns that separate C++ that merely
compiles from C++ that's idiomatic and safe. These are the conventions
experienced practitioners reach for automatically.

RAII (Resource Acquisition Is Initialization) ties a resource's lifetime to an
object's scope, so cleanup is automatic and exception-safe — the idea behind smart
pointers, locks, and file handles. The Rule of Zero says: design classes that need
no hand-written destructor, copy, or move operations by letting members manage
themselves; if you must write one, the Rule of Five says write them all. You'll
also revisit `const`-correctness and prefer-the-standard-library thinking. Getting
these habits into your fingers is what this whole course has been building toward.

## Further information

- [RAII](https://en.cppreference.com/w/cpp/language/raii)
- [Rule of three/five/zero](https://en.cppreference.com/w/cpp/language/rule_of_three)
- [Copy and move semantics](https://www.learncpp.com/cpp-tutorial/introduction-to-copy-constructors/)
