#include "cpplings_test.hpp"
#include <string>
#include <vector>

template <typename T>
int count_matching(const std::vector<T>& values, const T& target) {
    int count = 0;
    for (const T& v : values) {
        if (v == target) {
            ++count;
        }
    }
    return count;
}

CPPLINGS_TEST(counts_matching_any_type) {
    std::vector<int> nums = {1, 2, 2, 3, 2};
    CPPLINGS_ASSERT_EQ(count_matching(nums, 2), 3);

    std::vector<std::string> words = {"a", "b", "a", "a"};
    CPPLINGS_ASSERT_EQ(count_matching(words, std::string("a")), 3);

    std::vector<char> chars = {'x', 'y', 'z'};
    CPPLINGS_ASSERT_EQ(count_matching(chars, 'q'), 0);
}
