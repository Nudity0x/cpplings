// CHALLENGE — strings (std::string, find, substr, iteration).
//
// Builds on: loops (05), conditionals (04), functions (06).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: `count_words` returns how many words are in `sentence`. A word is a
// maximal run of non-space characters. There may be leading, trailing, or
// multiple spaces between words. Walk the string once, counting the number of
// times a non-space character follows a space (or the start).
//
//   ""            -> 0
//   "hello"       -> 1
//   "  a  b   c " -> 3
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>

int count_words(const std::string& sentence) {
    // TODO: scan the characters, counting the start of each word.
    return 0;
}

CPPLINGS_TEST(counts_words) {
    CPPLINGS_ASSERT_EQ(count_words(""), 0);
    CPPLINGS_ASSERT_EQ(count_words("hello"), 1);
    CPPLINGS_ASSERT_EQ(count_words("hello world"), 2);
    CPPLINGS_ASSERT_EQ(count_words("  a  b   c "), 3);
    CPPLINGS_ASSERT_EQ(count_words("   "), 0);
}
