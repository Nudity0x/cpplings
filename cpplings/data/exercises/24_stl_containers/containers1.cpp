// std::map<K, V> is an ordered associative container mapping keys to values.
// Insert with map[key] = value, look up with map.at(key) or map[key], and check
// presence with map.count(key) or map.find(key).
//
// TODO: `word_count` should count how many times each word appears in the
// vector and return the map. Complete the loop body. The test checks a couple
// of counts.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <map>
#include <string>
#include <vector>

std::map<std::string, int> word_count(const std::vector<std::string>& words) {
    std::map<std::string, int> counts;
    for (const std::string& w : words) {
        // TODO: increment the count for word `w`.
    }
    return counts;
}

CPPLINGS_TEST(counts_words) {
    std::map<std::string, int> counts =
        word_count({"a", "b", "a", "c", "a", "b"});

    CPPLINGS_ASSERT_EQ(counts.at("a"), 3);
    CPPLINGS_ASSERT_EQ(counts.at("b"), 2);
    CPPLINGS_ASSERT_EQ(counts.at("c"), 1);
}
