#include "cpplings_test.hpp"

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int choose(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

CPPLINGS_TEST(factorial_and_choose) {
    CPPLINGS_ASSERT_EQ(factorial(0), 1);
    CPPLINGS_ASSERT_EQ(factorial(5), 120);

    CPPLINGS_ASSERT_EQ(choose(5, 2), 10);
    CPPLINGS_ASSERT_EQ(choose(6, 3), 20);
    CPPLINGS_ASSERT_EQ(choose(4, 0), 1);
}
