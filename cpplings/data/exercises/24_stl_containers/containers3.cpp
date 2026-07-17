// std::pair<A, B> bundles two values. Access them with .first and .second, and
// build one with std::make_pair(a, b) or {a, b}.
//
// TODO: `min_max` should return a pair holding the smallest and largest values
// in the vector (in that order). Complete it. The test checks both members.
// You may assume the vector is non-empty.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <utility>
#include <vector>

std::pair<int, int> min_max(const std::vector<int>& values) {
    int lo = values[0];
    int hi = values[0];
    for (int v : values) {
        // TODO: update lo to the minimum and hi to the maximum.
    }
    // TODO: return a pair {lo, hi}.
    return {0, 0};
}

CPPLINGS_TEST(finds_min_and_max) {
    std::pair<int, int> result = min_max({4, 1, 7, 3, 9, 2});
    CPPLINGS_ASSERT_EQ(result.first, 1);
    CPPLINGS_ASSERT_EQ(result.second, 9);
}
