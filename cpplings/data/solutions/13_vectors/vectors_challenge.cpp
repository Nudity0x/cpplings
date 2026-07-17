#include "cpplings_test.hpp"
#include <vector>

std::vector<int> running_max(const std::vector<int>& values) {
    std::vector<int> result;
    int best = 0;
    bool seen = false;
    for (int v : values) {
        if (!seen || v > best) {
            best = v;
        }
        seen = true;
        result.push_back(best);
    }
    return result;
}

CPPLINGS_TEST(computes_running_max) {
    std::vector<int> result = running_max({3, 1, 4, 1, 5});
    std::vector<int> expected = {3, 3, 4, 4, 5};
    CPPLINGS_ASSERT(result == expected);

    CPPLINGS_ASSERT(running_max({}).empty());

    std::vector<int> single = running_max({7});
    CPPLINGS_ASSERT_EQ(single.size(), 1u);
    CPPLINGS_ASSERT_EQ(single[0], 7);
}
