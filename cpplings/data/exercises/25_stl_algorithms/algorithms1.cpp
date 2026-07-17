// <algorithm> provides std::sort, which sorts a range in place. Pass it the
// begin and end iterators of a container: std::sort(v.begin(), v.end()).
// By default it sorts ascending using operator<.
//
// TODO: Sort the vector ascending so the test sees it in order. Add the missing
// std::sort call.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <algorithm>
#include <vector>

std::vector<int> sorted_copy(std::vector<int> values) {
    // TODO: sort `values` ascending in place.
    return values;
}

CPPLINGS_TEST(sorts_ascending) {
    std::vector<int> result = sorted_copy({5, 2, 8, 1, 9, 3});
    std::vector<int> expected = {1, 2, 3, 5, 8, 9};
    CPPLINGS_ASSERT(result == expected);
}
