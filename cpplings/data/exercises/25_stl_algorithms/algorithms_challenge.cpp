// CHALLENGE — STL algorithms (compose several into a small pipeline).
//
// Builds on: lambdas (23), vectors (13), functions (06).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: `top_even_sum` takes a vector of ints and an int `k`, and returns the
// sum of the `k` largest EVEN values. Build it as a pipeline of algorithms:
//   1. Copy the even values into a new vector (std::copy_if with a lambda).
//   2. Sort them descending (std::sort with a comparator).
//   3. Sum the first min(k, size) of them (std::accumulate over a sub-range).
// If there are fewer than `k` evens, sum all of them.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <algorithm>
#include <numeric>
#include <vector>

// TODO: int top_even_sum(const std::vector<int>& values, int k);
int top_even_sum(const std::vector<int>& values, int k) {
    (void)values;
    (void)k;
    return 0;
}

CPPLINGS_TEST(sums_k_largest_evens) {
    std::vector<int> v = {5, 8, 2, 10, 7, 4, 9};
    // Evens: 8, 2, 10, 4 -> sorted desc: 10, 8, 4, 2
    CPPLINGS_ASSERT_EQ(top_even_sum(v, 2), 18);   // 10 + 8
    CPPLINGS_ASSERT_EQ(top_even_sum(v, 3), 22);   // 10 + 8 + 4
    CPPLINGS_ASSERT_EQ(top_even_sum(v, 10), 24);  // all evens
    CPPLINGS_ASSERT_EQ(top_even_sum({1, 3, 5}, 2), 0);  // no evens
}
