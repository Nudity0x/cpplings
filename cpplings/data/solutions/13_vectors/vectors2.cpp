// You can iterate a vector to compute over its elements.

#include "cpplings_test.hpp"
#include <vector>

CPPLINGS_TEST(sum_all) {
    std::vector<int> v = {2, 4, 6, 8};
    int total = 0;
    for (int n : v) {
        total += n;
    }
    CPPLINGS_ASSERT_EQ(total, 20);
}
