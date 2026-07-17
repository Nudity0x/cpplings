// CHALLENGE — arrays (fixed arrays, indexing, iteration).
//
// Builds on: loops (05), conditionals (04), functions (06).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: `second_largest` returns the second-largest distinct value in the array.
// Walk the array once, tracking the largest and second-largest values seen so
// far. You may assume the array has at least two elements and at least two
// distinct values.
//   - start `largest` and `second` at the smallest possible int
//   - for each value: if it beats `largest`, push the old largest down into
//     `second` and update `largest`; else if it beats `second` (and isn't equal
//     to largest), update `second`.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <climits>

int second_largest(const int* arr, int size) {
    // TODO: track the two largest distinct values in a single pass.
    (void)arr;
    (void)size;
    return 0;
}

CPPLINGS_TEST(finds_second_largest) {
    int a[] = {3, 7, 1, 9, 4};
    CPPLINGS_ASSERT_EQ(second_largest(a, 5), 7);

    int b[] = {10, 10, 8};
    CPPLINGS_ASSERT_EQ(second_largest(b, 3), 8);

    int c[] = {1, 2};
    CPPLINGS_ASSERT_EQ(second_largest(c, 2), 1);
}
