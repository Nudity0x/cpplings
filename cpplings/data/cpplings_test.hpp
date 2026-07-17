// cpplings_test.hpp — bundled, zero-dependency test + assertion helper.
//
// This single header is all an exercise needs to write tests. There is no
// external framework to install (no GoogleTest, no Catch2): include this file,
// register tests with CPPLINGS_TEST, assert inside them, and a main() is
// provided for you that runs every registered test.
//
//   #include "cpplings_test.hpp"
//
//   int add(int a, int b) { return a + b; }
//
//   CPPLINGS_TEST(add_works) {
//       CPPLINGS_ASSERT_EQ(add(2, 2), 4);
//   }
//
// Semantics:
//   * A failing assertion prints "file:line: <message>" and calls exit(1).
//   * The provided main() runs all tests; if all pass it prints a summary and
//     returns 0, otherwise the first failing assertion already exited nonzero.
//   * cpplings treats exit code 0 as "tests passed", nonzero as "failed".
//
// If an exercise only teaches syntax and has no tests, it should NOT include
// this header and instead define its own main() (mark it `test = false` in
// info.toml).

#ifndef CPPLINGS_TEST_HPP
#define CPPLINGS_TEST_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace cpplings {

// A registered test: a human-readable name and the function to run.
struct TestCase {
    const char* name;
    void (*fn)();
};

// Global registry of tests. Function-local static guarantees initialization
// order safety across translation units (only ever one TU here, but tidy).
inline std::vector<TestCase>& registry() {
    static std::vector<TestCase> tests;
    return tests;
}

// RAII helper: constructing one appends a test to the registry. Exercises use
// the CPPLINGS_TEST macro rather than touching this directly.
struct Registrar {
    Registrar(const char* name, void (*fn)()) { registry().push_back({name, fn}); }
};

// Report a failed assertion and abort the process with a nonzero exit code.
[[noreturn]] inline void fail(const char* file, int line, const std::string& message) {
    std::cerr << file << ":" << line << ": assertion failed: " << message << "\n";
    std::exit(1);
}

// Stringify a value for assertion messages; falls back gracefully for types
// without an operator<< via SFINAE-free overloading is overkill here, so we
// require streamable types in ASSERT_EQ/NE (the common case for exercises).
template <typename T>
std::string to_string(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

}  // namespace cpplings

// ---- Assertion macros -------------------------------------------------------
// __FILE__/__LINE__ give the learner a precise location. Conditions are shown
// verbatim so the failure message is self-explanatory.

#define CPPLINGS_ASSERT(cond)                                                   \
    do {                                                                        \
        if (!(cond)) {                                                          \
            ::cpplings::fail(__FILE__, __LINE__, "expected true: " #cond);      \
        }                                                                       \
    } while (0)

#define CPPLINGS_ASSERT_FALSE(cond)                                            \
    do {                                                                        \
        if (cond) {                                                             \
            ::cpplings::fail(__FILE__, __LINE__, "expected false: " #cond);     \
        }                                                                       \
    } while (0)

#define CPPLINGS_ASSERT_EQ(a, b)                                               \
    do {                                                                        \
        auto _cpplings_a = (a);                                                 \
        auto _cpplings_b = (b);                                                 \
        if (!(_cpplings_a == _cpplings_b)) {                                    \
            ::cpplings::fail(__FILE__, __LINE__,                                \
                             std::string(#a " == " #b " (") +                   \
                                 ::cpplings::to_string(_cpplings_a) + " != " +  \
                                 ::cpplings::to_string(_cpplings_b) + ")");     \
        }                                                                       \
    } while (0)

#define CPPLINGS_ASSERT_NE(a, b)                                               \
    do {                                                                        \
        auto _cpplings_a = (a);                                                 \
        auto _cpplings_b = (b);                                                 \
        if (!(_cpplings_a != _cpplings_b)) {                                    \
            ::cpplings::fail(__FILE__, __LINE__,                                \
                             std::string(#a " != " #b " (both ") +             \
                                 ::cpplings::to_string(_cpplings_a) + ")");     \
        }                                                                       \
    } while (0)

// ---- Test registration ------------------------------------------------------
// CPPLINGS_TEST(name) { ... } expands to a free function plus a static
// Registrar whose construction (at program startup) enrolls the test.

#define CPPLINGS_TEST(test_name)                                                \
    static void test_name();                                                    \
    static ::cpplings::Registrar _cpplings_reg_##test_name(#test_name,          \
                                                           &test_name);         \
    static void test_name()

// ---- Provided entry point ---------------------------------------------------
// Runs every registered test in registration order. The first failing
// assertion exits(1) before we get here to print success, so reaching the end
// means everything passed.

#ifndef CPPLINGS_NO_MAIN
int main() {
    auto& tests = ::cpplings::registry();
    for (const auto& test : tests) {
        test.fn();
    }
    std::cout << "All " << tests.size() << " test(s) passed.\n";
    return 0;
}
#endif  // CPPLINGS_NO_MAIN

#endif  // CPPLINGS_TEST_HPP
