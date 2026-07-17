// A range-based for loop visits each element of a container.
//
// TODO: Complete the range-based for loop to count how many values in `data`
// are even. The test expects 3.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <vector>

CPPLINGS_TEST(count_evens) {
    std::vector<int> data = {1, 2, 3, 4, 6, 7};
    int evens = 0;
    // TODO: for (int value : data) { ... }
    CPPLINGS_ASSERT_EQ(evens, 3);
}
