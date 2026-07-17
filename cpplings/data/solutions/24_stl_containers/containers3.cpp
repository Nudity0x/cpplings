#include "cpplings_test.hpp"
#include <utility>
#include <vector>

std::pair<int, int> min_max(const std::vector<int>& values) {
    int lo = values[0];
    int hi = values[0];
    for (int v : values) {
        if (v < lo) {
            lo = v;
        }
        if (v > hi) {
            hi = v;
        }
    }
    return {lo, hi};
}

CPPLINGS_TEST(finds_min_and_max) {
    std::pair<int, int> result = min_max({4, 1, 7, 3, 9, 2});
    CPPLINGS_ASSERT_EQ(result.first, 1);
    CPPLINGS_ASSERT_EQ(result.second, 9);
}
