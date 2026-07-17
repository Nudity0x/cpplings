// std::optional<T> holds either a value or nothing. Check it with has_value()
// or by using it in a bool context; read the value with * or .value().
//
// TODO: `first_even` should return the first even number in the vector wrapped
// in an optional, or std::nullopt if there is none. Complete it. The test
// checks both the found and not-found cases.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <optional>
#include <vector>

std::optional<int> first_even(const std::vector<int>& nums) {
    for (int n : nums) {
        // TODO: if n is even, return it (wrapped in an optional).
    }
    // TODO: return nullopt when nothing was found.
    return 0;
}

CPPLINGS_TEST(finds_first_even) {
    std::optional<int> found = first_even({1, 3, 4, 7});
    CPPLINGS_ASSERT(found.has_value());
    CPPLINGS_ASSERT_EQ(*found, 4);

    std::optional<int> none = first_even({1, 3, 5});
    CPPLINGS_ASSERT_FALSE(none.has_value());
}
