// Iterating a vector and transforming each element in place is a common task.
//
// TODO: Fix `double_all` so it multiplies every element of the vector by 2.
// Take the vector by reference so the caller sees the change.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <vector>

void double_all(std::vector<int>& v) {
    // TODO: loop over v and double each element in place.
}

CPPLINGS_TEST(doubles_elements) {
    std::vector<int> nums = {1, 2, 3};
    double_all(nums);
    CPPLINGS_ASSERT_EQ(nums[0], 2);
    CPPLINGS_ASSERT_EQ(nums[1], 4);
    CPPLINGS_ASSERT_EQ(nums[2], 6);
}
