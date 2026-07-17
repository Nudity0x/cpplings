// CHALLENGE — functions (parameters, returns, overloading, recursion).
//
// Builds on: conditionals (04), loops (05).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: Implement two functions that work together.
//   1. `factorial(n)` returns n! (the product 1*2*...*n). factorial(0) is 1.
//      Write it recursively OR with a loop.
//   2. `choose(n, k)` returns the binomial coefficient "n choose k", defined as
//      factorial(n) / (factorial(k) * factorial(n - k)). Call factorial from it.
// This shows a function calling another function you wrote.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

int factorial(int n) {
    // TODO: return n! (factorial(0) == 1).
    return 0;
}

int choose(int n, int k) {
    // TODO: return factorial(n) / (factorial(k) * factorial(n - k)).
    return 0;
}

CPPLINGS_TEST(factorial_and_choose) {
    CPPLINGS_ASSERT_EQ(factorial(0), 1);
    CPPLINGS_ASSERT_EQ(factorial(5), 120);

    CPPLINGS_ASSERT_EQ(choose(5, 2), 10);
    CPPLINGS_ASSERT_EQ(choose(6, 3), 20);
    CPPLINGS_ASSERT_EQ(choose(4, 0), 1);
}
