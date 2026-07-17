#include "cpplings_test.hpp"
#include <algorithm>
#include <vector>

std::vector<int> sorted_copy(std::vector<int> values) {
    std::sort(values.begin(), values.end());
    return values;
}

CPPLINGS_TEST(sorts_ascending) {
    std::vector<int> result = sorted_copy({5, 2, 8, 1, 9, 3});
    std::vector<int> expected = {1, 2, 3, 5, 8, 9};
    CPPLINGS_ASSERT(result == expected);
}
