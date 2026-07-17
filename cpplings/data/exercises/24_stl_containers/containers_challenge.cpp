// CHALLENGE — STL containers (map, set, and their idioms working together).
//
// Builds on: strings (08), vectors (13), references (10).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: Tally a word frequency table, then answer questions about it.
//   1. `tally` returns a std::map<std::string, int> counting how many times each
//      word appears in the input vector. operator[] value-initializes missing
//      keys to 0, so `counts[w]++` is the idiom.
//   2. `unique_words` returns the number of distinct words (the map's size).
//   3. `most_common` returns the word with the highest count. On a tie, return
//      the one that is smallest lexicographically (std::map iterates in sorted
//      key order, so the first max you meet wins that tie naturally).
// Complete all three so the test reads like real text processing.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <map>
#include <string>
#include <vector>

std::map<std::string, int> tally(const std::vector<std::string>& words) {
    // TODO: count occurrences of each word.
    (void)words;
    return {};
}

int unique_words(const std::map<std::string, int>& counts) {
    // TODO: return how many distinct words there are.
    (void)counts;
    return 0;
}

std::string most_common(const std::map<std::string, int>& counts) {
    // TODO: return the highest-count word (lexicographically smallest on ties).
    (void)counts;
    return "";
}

CPPLINGS_TEST(word_frequency_table) {
    std::vector<std::string> words = {
        "red", "blue", "red", "green", "blue", "red"};

    std::map<std::string, int> counts = tally(words);
    CPPLINGS_ASSERT_EQ(counts.at("red"), 3);
    CPPLINGS_ASSERT_EQ(counts.at("blue"), 2);
    CPPLINGS_ASSERT_EQ(counts.at("green"), 1);

    CPPLINGS_ASSERT_EQ(unique_words(counts), 3);
    CPPLINGS_ASSERT_EQ(most_common(counts), std::string("red"));

    // Tie between "a" and "b" at count 1 -> lexicographically smallest is "a".
    std::map<std::string, int> tie = tally({"b", "a"});
    CPPLINGS_ASSERT_EQ(most_common(tie), std::string("a"));
}
