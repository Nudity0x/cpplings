#include "cpplings_test.hpp"

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int d = 2; d <= n / 2; ++d) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

CPPLINGS_TEST(detects_primes) {
    CPPLINGS_ASSERT_FALSE(is_prime(0));
    CPPLINGS_ASSERT_FALSE(is_prime(1));
    CPPLINGS_ASSERT(is_prime(2));
    CPPLINGS_ASSERT(is_prime(3));
    CPPLINGS_ASSERT_FALSE(is_prime(9));
    CPPLINGS_ASSERT(is_prime(13));
    CPPLINGS_ASSERT_FALSE(is_prime(100));
    CPPLINGS_ASSERT(is_prime(97));
}
