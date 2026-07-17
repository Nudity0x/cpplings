// Iterators come in flavors. A const_iterator (from cbegin()/cend()) gives
// read-only access. Reverse iterators (rbegin()/rend()) walk a container
// backwards — *rbegin() is the last element.
//
// TODO: `reversed` should return a new vector with the elements in reverse
// order. Build it by iterating from rbegin() to rend(). Complete the loop.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <vector>

std::vector<int> reversed(const std::vector<int>& values) {
    std::vector<int> out;
    // TODO: push each element from values.rbegin() to values.rend() into out.
    return out;
}

CPPLINGS_TEST(reverses_with_iterators) {
    std::vector<int> result = reversed({1, 2, 3, 4});
    std::vector<int> expected = {4, 3, 2, 1};
    CPPLINGS_ASSERT(result == expected);
}
