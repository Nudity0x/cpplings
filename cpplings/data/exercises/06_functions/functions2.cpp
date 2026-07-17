// Function parameters have types, and the call must match.
//
// TODO: The function `add` is declared to return void but should return the
// sum. Fix the return type and add a return statement.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

void add(int a, int b) {
    a + b;
}

CPPLINGS_TEST(add_works) {
    CPPLINGS_ASSERT_EQ(add(2, 3), 5);
}
