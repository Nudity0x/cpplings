// `const` marks a value that must not change.
//
// TODO: This code tries to modify a const variable, which won't compile.
// Change the declaration so `max` can be assigned, OR remove the reassignment
// and set the correct value at initialization. The test expects max == 100.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

CPPLINGS_TEST(max_is_100) {
    const int max = 50;
    max = 100;
    CPPLINGS_ASSERT_EQ(max, 100);
}
