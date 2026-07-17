#include "cpplings_test.hpp"
#include <numeric>
#include <vector>

int product(const std::vector<int>& values) {
    return std::accumulate(values.begin(), values.end(), 1,
                           [](int acc, int x) { return acc * x; });
}

CPPLINGS_TEST(computes_product) {
    CPPLINGS_ASSERT_EQ(product({1, 2, 3, 4}), 24);
    CPPLINGS_ASSERT_EQ(product({5, 5}), 25);
    CPPLINGS_ASSERT_EQ(product({}), 1);
}
