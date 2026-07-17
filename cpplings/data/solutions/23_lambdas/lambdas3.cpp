#include "cpplings_test.hpp"
#include <vector>

template <typename Predicate>
int count_if(const std::vector<int>& nums, Predicate pred) {
    int count = 0;
    for (int n : nums) {
        if (pred(n)) {
            count += 1;
        }
    }
    return count;
}

CPPLINGS_TEST(lambda_as_predicate) {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};

    int result = count_if(nums, [](int n) { return n > 3; });

    CPPLINGS_ASSERT_EQ(result, 3);
}
