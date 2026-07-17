// CHALLENGE — pointers (dereference, null checks, pointer arithmetic).
//
// Builds on: arrays (07), loops (05), conditionals (04).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: `reverse_in_place` reverses an array of ints in place using only
// pointers — no indexing with []. Set one pointer to the first element and one
// to the last, then swap what they point at and walk them toward each other
// until they meet. If the pointer is null or size <= 1, do nothing.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

void reverse_in_place(int* data, int size) {
    // TODO: use two pointers (front and back) and swap through them.
}

CPPLINGS_TEST(reverses_with_pointers) {
    int a[] = {1, 2, 3, 4, 5};
    reverse_in_place(a, 5);
    CPPLINGS_ASSERT_EQ(a[0], 5);
    CPPLINGS_ASSERT_EQ(a[1], 4);
    CPPLINGS_ASSERT_EQ(a[2], 3);
    CPPLINGS_ASSERT_EQ(a[3], 2);
    CPPLINGS_ASSERT_EQ(a[4], 1);

    int b[] = {10, 20};
    reverse_in_place(b, 2);
    CPPLINGS_ASSERT_EQ(b[0], 20);
    CPPLINGS_ASSERT_EQ(b[1], 10);

    // Null and tiny inputs must be safe no-ops.
    reverse_in_place(nullptr, 0);
    int c[] = {42};
    reverse_in_place(c, 1);
    CPPLINGS_ASSERT_EQ(c[0], 42);
}
