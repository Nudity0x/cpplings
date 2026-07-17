// A `const&` parameter avoids copying while promising not to modify the arg.

#include "cpplings_test.hpp"
#include <vector>

int sum(const std::vector<int>& v) {
    int total = 0;
    for (int n : v) {
        total += n;
    }
    return total;
}

CPPLINGS_TEST(sums_vector) {
    std::vector<int> nums = {1, 2, 3, 4};
    CPPLINGS_ASSERT_EQ(sum(nums), 10);
}
