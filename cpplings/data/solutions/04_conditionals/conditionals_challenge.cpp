#include "cpplings_test.hpp"

char letter_grade(int score) {
    if (score < 0 || score > 100) {
        return '?';
    }
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    }
    return 'F';
}

CPPLINGS_TEST(maps_scores_to_grades) {
    CPPLINGS_ASSERT_EQ(letter_grade(95), 'A');
    CPPLINGS_ASSERT_EQ(letter_grade(83), 'B');
    CPPLINGS_ASSERT_EQ(letter_grade(71), 'C');
    CPPLINGS_ASSERT_EQ(letter_grade(65), 'D');
    CPPLINGS_ASSERT_EQ(letter_grade(40), 'F');
    CPPLINGS_ASSERT_EQ(letter_grade(-5), '?');
    CPPLINGS_ASSERT_EQ(letter_grade(101), '?');
}
