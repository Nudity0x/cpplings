// std::array is a fixed-size array that knows its own size.

#include "cpplings_test.hpp"
#include <array>

CPPLINGS_TEST(array_sum) {
    std::array<int, 4> nums = {10, 20, 30, 40};
    int sum = 0;
    for (int n : nums) {
        sum += n;
    }
    CPPLINGS_ASSERT_EQ(sum, 100);
}
