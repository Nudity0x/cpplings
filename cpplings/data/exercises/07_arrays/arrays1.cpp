// std::array is a fixed-size array that knows its own size.
//
// TODO: The array is declared to hold 3 ints but initialized with 4 values,
// which won't compile. Fix the size so it matches, then make the test pass.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <array>

CPPLINGS_TEST(array_sum) {
    std::array<int, 3> nums = {10, 20, 30, 40};
    int sum = 0;
    for (int n : nums) {
        sum += n;
    }
    CPPLINGS_ASSERT_EQ(sum, 100);
}
