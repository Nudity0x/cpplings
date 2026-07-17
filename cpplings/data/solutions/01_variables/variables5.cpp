// `auto` lets the compiler deduce a variable's type from its initializer.

#include "cpplings_test.hpp"

CPPLINGS_TEST(auto_deduces_int) {
    int a = 10;
    int b = 20;
    auto total = a + b;
    CPPLINGS_ASSERT_EQ(total, 30);
}
