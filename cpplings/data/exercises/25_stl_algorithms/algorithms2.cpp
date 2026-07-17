// std::count counts how many elements in a range equal a value:
// std::count(v.begin(), v.end(), target). std::find returns an iterator to the
// first match, or end() if not found.
//
// TODO: `occurrences` should return how many times `target` appears in the
// vector. Use std::count. The test checks a few targets.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <algorithm>
#include <vector>

int occurrences(const std::vector<int>& values, int target) {
    // TODO: return the number of elements equal to `target` using std::count.
    return 0;
}

CPPLINGS_TEST(counts_occurrences) {
    std::vector<int> nums = {1, 2, 2, 3, 2, 4};
    CPPLINGS_ASSERT_EQ(occurrences(nums, 2), 3);
    CPPLINGS_ASSERT_EQ(occurrences(nums, 4), 1);
    CPPLINGS_ASSERT_EQ(occurrences(nums, 9), 0);
}
