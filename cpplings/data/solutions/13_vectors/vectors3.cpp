// Iterating a vector and transforming each element in place is a common task.

#include "cpplings_test.hpp"
#include <vector>

void double_all(std::vector<int>& v) {
    for (int& n : v) {
        n *= 2;
    }
}

CPPLINGS_TEST(doubles_elements) {
    std::vector<int> nums = {1, 2, 3};
    double_all(nums);
    CPPLINGS_ASSERT_EQ(nums[0], 2);
    CPPLINGS_ASSERT_EQ(nums[1], 4);
    CPPLINGS_ASSERT_EQ(nums[2], 6);
}
