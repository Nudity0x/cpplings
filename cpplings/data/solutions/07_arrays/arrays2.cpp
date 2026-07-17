// Indexing an array is zero-based: the first element is [0].

#include "cpplings_test.hpp"
#include <array>

CPPLINGS_TEST(third_element) {
    std::array<int, 3> nums = {10, 20, 30};
    int third = nums[2];
    CPPLINGS_ASSERT_EQ(third, 30);
}
