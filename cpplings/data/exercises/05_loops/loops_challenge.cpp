// CHALLENGE — loops (for, while, nested, break/continue).
//
// Builds on: operators (03), conditionals (04).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: `is_prime` returns true if `n` is a prime number (greater than 1 and
// divisible only by 1 and itself). Handle the edge cases:
//   - n < 2            -> not prime
//   - check divisors from 2 up to n/2 (or sqrt(n) if you prefer) with a loop
//   - the moment you find a divisor, you can stop early
// Use a loop plus a conditional. Return a bool.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

bool is_prime(int n) {
    // TODO: return false for n < 2, then loop to look for any divisor.
    return false;
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
