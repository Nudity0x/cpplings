#include "cpplings_test.hpp"

CPPLINGS_TEST(basic_lambda) {
    auto square = [](int n) { return n * n; };

    CPPLINGS_ASSERT_EQ(square(3), 9);
    CPPLINGS_ASSERT_EQ(square(5), 25);
}
