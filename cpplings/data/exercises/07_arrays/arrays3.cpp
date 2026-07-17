// std::array is a fixed-size array that knows its own size.
//
// TODO: Fix `sum_all` so it adds every element of the array and returns the
// total. Use a range-based for loop.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <array>

int sum_all(const std::array<int, 5>& values) {
    int total = 0;
    // TODO: iterate over `values` and accumulate into `total`.
    return total;
}

CPPLINGS_TEST(sums_array) {
    std::array<int, 5> nums = {1, 2, 3, 4, 5};
    CPPLINGS_ASSERT_EQ(sum_all(nums), 15);
}
