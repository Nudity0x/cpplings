// CHALLENGE — vectors (std::vector, push_back, iteration, size).
//
// Builds on: loops (05), conditionals (04), functions (06).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: `running_max` takes a vector of ints and returns a NEW vector of the
// same length where each element is the largest value seen so far (a running
// maximum). For {3, 1, 4, 1, 5} the result is {3, 3, 4, 4, 5}. Build the result
// with push_back. An empty input gives an empty output.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <vector>

std::vector<int> running_max(const std::vector<int>& values) {
    // TODO: track the max so far, pushing it for each element.
    return {};
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
