// std::array is a fixed-size array that knows its own size.

#include "cpplings_test.hpp"
#include <array>

int sum_all(const std::array<int, 5>& values) {
    int total = 0;
    for (int v : values) {
        total += v;
    }
    return total;
}

CPPLINGS_TEST(sums_array) {
    std::array<int, 5> nums = {1, 2, 3, 4, 5};
    CPPLINGS_ASSERT_EQ(sum_all(nums), 15);
}
