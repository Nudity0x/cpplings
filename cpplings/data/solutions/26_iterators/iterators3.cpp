#include "cpplings_test.hpp"
#include <vector>

std::vector<int> reversed(const std::vector<int>& values) {
    std::vector<int> out;
    for (auto it = values.rbegin(); it != values.rend(); ++it) {
        out.push_back(*it);
    }
    return out;
}

CPPLINGS_TEST(reverses_with_iterators) {
    std::vector<int> result = reversed({1, 2, 3, 4});
    std::vector<int> expected = {4, 3, 2, 1};
    CPPLINGS_ASSERT(result == expected);
}
