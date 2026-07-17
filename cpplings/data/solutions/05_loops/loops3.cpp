// A range-based for loop visits each element of a container.

#include "cpplings_test.hpp"
#include <vector>

CPPLINGS_TEST(count_evens) {
    std::vector<int> data = {1, 2, 3, 4, 6, 7};
    int evens = 0;
    for (int value : data) {
        if (value % 2 == 0) {
            ++evens;
        }
    }
    CPPLINGS_ASSERT_EQ(evens, 3);
}
