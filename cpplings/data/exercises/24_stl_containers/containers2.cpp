// std::set<T> stores unique, sorted elements. Insert with insert(), check
// membership with count() (0 or 1) or find(). Duplicates are ignored.
//
// TODO: `unique_count` should return how many *distinct* values are in the
// vector. Insert every value into a set and return its size. Complete it.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <set>
#include <vector>

int unique_count(const std::vector<int>& values) {
    std::set<int> seen;
    // TODO: insert each value into `seen`.
    // TODO: return the number of distinct values.
    return 0;
}

CPPLINGS_TEST(counts_distinct) {
    CPPLINGS_ASSERT_EQ(unique_count({1, 2, 2, 3, 3, 3}), 3);
    CPPLINGS_ASSERT_EQ(unique_count({5, 5, 5, 5}), 1);
    CPPLINGS_ASSERT_EQ(unique_count({}), 0);
}
