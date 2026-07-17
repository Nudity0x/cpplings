#include "cpplings_test.hpp"

CPPLINGS_TEST(capture_by_value) {
    int factor = 10;

    auto scale = [factor](int x) { return x * factor; };

    CPPLINGS_ASSERT_EQ(scale(3), 30);
    CPPLINGS_ASSERT_EQ(scale(7), 70);
}
