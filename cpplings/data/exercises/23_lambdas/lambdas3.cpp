// Lambdas are often passed to functions as callbacks or predicates. A function
// can accept one via a template parameter or std::function. Here `count_if`
// takes a predicate and counts elements for which it returns true.
//
// TODO: Call count_if with a lambda predicate that returns true for numbers
// greater than 3. The test checks the count.
//
// I AM NOT DONE

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

    // TODO: pass a lambda that returns true when n > 3.
    int result = count_if(nums, /* your lambda here */ 0);

    CPPLINGS_ASSERT_EQ(result, 3);
}
