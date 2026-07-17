// CHALLENGE — conditionals (if/else, switch, comparison).
//
// Builds on: operators (03).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: `letter_grade` converts a 0-100 score into a letter using the standard
// scale, but ALSO validates its input:
//   - score < 0 or score > 100  -> return '?'
//   - 90..100 -> 'A'
//   - 80..89  -> 'B'
//   - 70..79  -> 'C'
//   - 60..69  -> 'D'
//   - below 60 (but >= 0) -> 'F'
// Use if/else if. Return a char.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

char letter_grade(int score) {
    // TODO: validate the range, then map the score to a letter grade.
    return '?';
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
