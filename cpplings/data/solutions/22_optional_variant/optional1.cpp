#include "cpplings_test.hpp"
#include <optional>
#include <vector>

std::optional<int> first_even(const std::vector<int>& nums) {
    for (int n : nums) {
        if (n % 2 == 0) {
            return n;
        }
    }
    return std::nullopt;
}

CPPLINGS_TEST(finds_first_even) {
    std::optional<int> found = first_even({1, 3, 4, 7});
    CPPLINGS_ASSERT(found.has_value());
    CPPLINGS_ASSERT_EQ(*found, 4);

    std::optional<int> none = first_even({1, 3, 5});
    CPPLINGS_ASSERT_FALSE(none.has_value());
}
