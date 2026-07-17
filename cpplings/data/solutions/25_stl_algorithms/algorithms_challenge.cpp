#include "cpplings_test.hpp"
#include <algorithm>
#include <numeric>
#include <vector>

int top_even_sum(const std::vector<int>& values, int k) {
    std::vector<int> evens;
    std::copy_if(values.begin(), values.end(), std::back_inserter(evens),
                 [](int n) { return n % 2 == 0; });
    std::sort(evens.begin(), evens.end(), [](int a, int b) { return a > b; });

    std::size_t take = std::min(static_cast<std::size_t>(k), evens.size());
    return std::accumulate(evens.begin(), evens.begin() + static_cast<std::ptrdiff_t>(take), 0);
}

CPPLINGS_TEST(sums_k_largest_evens) {
    std::vector<int> v = {5, 8, 2, 10, 7, 4, 9};
    CPPLINGS_ASSERT_EQ(top_even_sum(v, 2), 18);
    CPPLINGS_ASSERT_EQ(top_even_sum(v, 3), 22);
    CPPLINGS_ASSERT_EQ(top_even_sum(v, 10), 24);
    CPPLINGS_ASSERT_EQ(top_even_sum({1, 3, 5}, 2), 0);
}
