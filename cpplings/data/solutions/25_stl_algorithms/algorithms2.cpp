#include "cpplings_test.hpp"
#include <algorithm>
#include <vector>

int occurrences(const std::vector<int>& values, int target) {
    return static_cast<int>(std::count(values.begin(), values.end(), target));
}

CPPLINGS_TEST(counts_occurrences) {
    std::vector<int> nums = {1, 2, 2, 3, 2, 4};
    CPPLINGS_ASSERT_EQ(occurrences(nums, 2), 3);
    CPPLINGS_ASSERT_EQ(occurrences(nums, 4), 1);
    CPPLINGS_ASSERT_EQ(occurrences(nums, 9), 0);
}
