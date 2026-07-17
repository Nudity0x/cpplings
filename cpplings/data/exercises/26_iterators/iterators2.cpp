// <iterator> offers std::distance(first, last) to count elements between two
// iterators, and std::next(it, n) to advance a copy of an iterator. These work
// even for containers without random access.
//
// TODO: `index_of` should return the position of the first element equal to
// `target`, or -1 if absent. Use std::find, then std::distance from begin() to
// the result. The test checks a present and an absent value.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <algorithm>
#include <iterator>
#include <vector>

int index_of(const std::vector<int>& values, int target) {
    auto it = std::find(values.begin(), values.end(), target);
    // TODO: if it == end(), return -1; otherwise return the distance from begin().
    return -1;
}

CPPLINGS_TEST(finds_index) {
    std::vector<int> nums = {10, 20, 30, 40};
    CPPLINGS_ASSERT_EQ(index_of(nums, 30), 2);
    CPPLINGS_ASSERT_EQ(index_of(nums, 10), 0);
    CPPLINGS_ASSERT_EQ(index_of(nums, 99), -1);
}
