// CHALLENGE — templates (function templates, class templates, multiple params).
//
// Builds on: functions (06), references (10), vectors (13).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: Write a function template `count_matching` that takes a std::vector<T>
// and a value of type T, and returns how many elements equal that value. It must
// work for any comparable type (int, std::string, char, ...). Take both the
// vector and the target by const reference. The test uses several types.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>
#include <vector>

// TODO: turn this into a template on T so it works for any comparable type.
int count_matching(const std::vector<int>& values, const int& target) {
    // TODO: count how many elements equal target.
    return 0;
}

CPPLINGS_TEST(counts_matching_any_type) {
    std::vector<int> nums = {1, 2, 2, 3, 2};
    CPPLINGS_ASSERT_EQ(count_matching(nums, 2), 3);

    std::vector<std::string> words = {"a", "b", "a", "a"};
    CPPLINGS_ASSERT_EQ(count_matching(words, std::string("a")), 3);

    std::vector<char> chars = {'x', 'y', 'z'};
    CPPLINGS_ASSERT_EQ(count_matching(chars, 'q'), 0);
}
