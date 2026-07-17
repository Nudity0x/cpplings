// `auto` lets the compiler deduce a variable's type from its initializer.
//
// TODO: Use `auto` to declare `total` from the sum below. It must end up an
// `int` equal to 30 so the test passes.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

CPPLINGS_TEST(auto_deduces_int) {
    int a = 10;
    int b = 20;
    // TODO: replace the line below with an `auto` declaration of `total`.
    total = a + b;
    CPPLINGS_ASSERT_EQ(total, 30);
}
