#include "cpplings_test.hpp"
#include <vector>

int sum_with_iterators(const std::vector<int>& values) {
    int total = 0;
    for (auto it = values.begin(); it != values.end(); ++it) {
        total += *it;
    }
    return total;
}

CPPLINGS_TEST(iterate_and_sum) {
    CPPLINGS_ASSERT_EQ(sum_with_iterators({1, 2, 3, 4}), 10);
    CPPLINGS_ASSERT_EQ(sum_with_iterators({}), 0);
}
