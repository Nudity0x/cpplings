// CHALLENGE — iterators (write a range-based algorithm against any container).
//
// Builds on: iterators (this section), templates (15), functions (06).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: Write `dedup_adjacent`, a function template that returns a new
// container of the same element type with consecutive duplicates collapsed to
// a single element (like std::unique, but you write the loop by hand).
//   - Take the input by const reference and iterate with begin()/end().
//   - Keep an element only when it differs from the previously kept one.
//   - The first element is always kept.
// It should work for any element type comparable with == (int, std::string).
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>
#include <vector>

// TODO: template <typename T>
//       std::vector<T> dedup_adjacent(const std::vector<T>& values);
template <typename T>
std::vector<T> dedup_adjacent(const std::vector<T>& values) {
    (void)values;
    return {};
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
