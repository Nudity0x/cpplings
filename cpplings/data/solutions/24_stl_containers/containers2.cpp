#include "cpplings_test.hpp"
#include <set>
#include <vector>

int unique_count(const std::vector<int>& values) {
    std::set<int> seen;
    for (int v : values) {
        seen.insert(v);
    }
    return static_cast<int>(seen.size());
}

CPPLINGS_TEST(counts_distinct) {
    CPPLINGS_ASSERT_EQ(unique_count({1, 2, 2, 3, 3, 3}), 3);
    CPPLINGS_ASSERT_EQ(unique_count({5, 5, 5, 5}), 1);
    CPPLINGS_ASSERT_EQ(unique_count({}), 0);
}
