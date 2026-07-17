// std::vector is a dynamic array that grows as you push onto it.

#include "cpplings_test.hpp"
#include <vector>

CPPLINGS_TEST(push_back) {
    std::vector<int> v = {1, 2};
    v.push_back(3);
    CPPLINGS_ASSERT_EQ(static_cast<int>(v.size()), 3);
    CPPLINGS_ASSERT_EQ(v[2], 3);
}
