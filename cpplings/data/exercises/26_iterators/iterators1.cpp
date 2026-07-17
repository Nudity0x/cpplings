// An iterator points into a container. begin() gives an iterator to the first
// element, end() one past the last. Dereference with * and advance with ++.
// This is the machinery range-based for loops use under the hood.
//
// TODO: `sum_with_iterators` should add up every element using an explicit
// iterator loop (begin() to end()). Complete the loop. The test checks the sum.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <vector>

int sum_with_iterators(const std::vector<int>& values) {
    int total = 0;
    // TODO: loop from values.begin() to values.end(), adding *it to total.
    return total;
}

CPPLINGS_TEST(iterate_and_sum) {
    CPPLINGS_ASSERT_EQ(sum_with_iterators({1, 2, 3, 4}), 10);
    CPPLINGS_ASSERT_EQ(sum_with_iterators({}), 0);
}
