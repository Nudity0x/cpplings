#include "cpplings_test.hpp"
#include <string>
#include <vector>

template <typename T>
std::vector<T> dedup_adjacent(const std::vector<T>& values) {
    std::vector<T> out;
    for (auto it = values.begin(); it != values.end(); ++it) {
        if (out.empty() || !(*it == out.back())) {
            out.push_back(*it);
        }
    }
    return out;
}

CPPLINGS_TEST(collapses_adjacent_duplicates) {
    std::vector<int> nums = {1, 1, 2, 3, 3, 3, 2, 2};
    std::vector<int> expected = {1, 2, 3, 2};
    CPPLINGS_ASSERT(dedup_adjacent(nums) == expected);

    std::vector<std::string> words = {"a", "a", "b", "a"};
    std::vector<std::string> expected_words = {"a", "b", "a"};
    CPPLINGS_ASSERT(dedup_adjacent(words) == expected_words);

    std::vector<int> empty;
    CPPLINGS_ASSERT(dedup_adjacent(empty).empty());
}
