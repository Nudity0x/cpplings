// A `const&` parameter avoids copying while promising not to modify the arg.
// It's the idiomatic way to pass large objects you only need to read.
//
// TODO: Fix `sum` so it takes its vector by const reference (not by value) and
// returns the total. The test relies on the values being read correctly.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <vector>

// TODO: change the parameter to `const std::vector<int>&`.
int sum(std::vector<int> v) {
    int total = 0;
    for (int n : v) {
        total += n;
    }
    return total;
}

CPPLINGS_TEST(sums_vector) {
    std::vector<int> nums = {1, 2, 3, 4};
    CPPLINGS_ASSERT_EQ(sum(nums), 10);
}
