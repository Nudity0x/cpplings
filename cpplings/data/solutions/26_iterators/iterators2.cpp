#include "cpplings_test.hpp"
#include <algorithm>
#include <iterator>
#include <vector>

int index_of(const std::vector<int>& values, int target) {
    auto it = std::find(values.begin(), values.end(), target);
    if (it == values.end()) {
        return -1;
    }
    return static_cast<int>(std::distance(values.begin(), it));
}

CPPLINGS_TEST(finds_index) {
    std::vector<int> nums = {10, 20, 30, 40};
    CPPLINGS_ASSERT_EQ(index_of(nums, 30), 2);
    CPPLINGS_ASSERT_EQ(index_of(nums, 10), 0);
    CPPLINGS_ASSERT_EQ(index_of(nums, 99), -1);
}
