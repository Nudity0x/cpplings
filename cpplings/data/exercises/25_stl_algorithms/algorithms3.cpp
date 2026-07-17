// std::accumulate (from <numeric>) folds a range into a single value, starting
// from an initial value: std::accumulate(v.begin(), v.end(), 0). With a fourth
// argument you can supply a custom binary operation instead of addition.
//
// TODO: `product` should multiply every element together, starting from 1. Use
// std::accumulate with a lambda (or std::multiplies) as the operation. The test
// checks the product of a few vectors.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <numeric>
#include <vector>

int product(const std::vector<int>& values) {
    // TODO: return the product of all elements using std::accumulate, init 1.
    return 0;
}

CPPLINGS_TEST(computes_product) {
    CPPLINGS_ASSERT_EQ(product({1, 2, 3, 4}), 24);
    CPPLINGS_ASSERT_EQ(product({5, 5}), 25);
    CPPLINGS_ASSERT_EQ(product({}), 1);
}
