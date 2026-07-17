#include "cpplings_test.hpp"
#include <vector>
#include <utility>

int sum(std::vector<int> v) {
    int total = 0;
    for (int x : v) {
        total += x;
    }
    return total;
}

CPPLINGS_TEST(move_into_function) {
    std::vector<int> numbers = {1, 2, 3, 4};
    int result = sum(std::move(numbers));
    CPPLINGS_ASSERT_EQ(result, 10);
}
