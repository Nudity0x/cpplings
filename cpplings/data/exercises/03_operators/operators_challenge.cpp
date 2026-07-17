// CHALLENGE — operators (arithmetic, comparison, logic, modulo).
//
// Builds on: variables (01), conditionals come next but aren't needed here.
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: A year is a leap year when it is divisible by 4, EXCEPT century years
// (divisible by 100) which are only leap years if also divisible by 400.
// Implement `is_leap_year` using only the % and && / || / == operators — no
// `if` statements. Return the boolean expression directly.
//
//   divisible by 4 AND (not divisible by 100 OR divisible by 400)
//
// I AM NOT DONE

#include "cpplings_test.hpp"

bool is_leap_year(int year) {
    // TODO: return the leap-year expression using %, &&, ||, ==.
    return false;
}

CPPLINGS_TEST(detects_leap_years) {
    CPPLINGS_ASSERT(is_leap_year(2000));   // divisible by 400 -> leap
    CPPLINGS_ASSERT(is_leap_year(2024));   // divisible by 4, not 100 -> leap
    CPPLINGS_ASSERT_FALSE(is_leap_year(1900));  // divisible by 100, not 400 -> not leap
    CPPLINGS_ASSERT_FALSE(is_leap_year(2023));  // not divisible by 4 -> not leap
}
