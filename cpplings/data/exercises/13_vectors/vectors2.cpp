// You can iterate a vector to compute over its elements.
//
// TODO: Complete the loop so `total` becomes the sum of all elements.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <vector>

CPPLINGS_TEST(sum_all) {
    std::vector<int> v = {2, 4, 6, 8};
    int total = 0;
    // TODO: loop over v and add each element to total
    CPPLINGS_ASSERT_EQ(total, 20);
}
