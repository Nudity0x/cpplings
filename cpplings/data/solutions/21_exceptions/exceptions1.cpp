#include "cpplings_test.hpp"
#include <stdexcept>

int safe_divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("divide by zero");
    }
    return a / b;
}

CPPLINGS_TEST(throws_on_zero) {
    CPPLINGS_ASSERT_EQ(safe_divide(10, 2), 5);

    bool threw = false;
    try {
        safe_divide(1, 0);
    } catch (const std::runtime_error&) {
        threw = true;
    }
    CPPLINGS_ASSERT(threw);
}
