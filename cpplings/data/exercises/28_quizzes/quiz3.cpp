// QUIZ 3 — combining maps, optional, and strings.
//
// No new concepts. A lookup table that returns an optional: present keys yield
// their value, missing keys yield nullopt. This is the safe alternative to
// returning a sentinel like -1.
//
// TODO: `lookup` should search the map for `key`. If found, return its value
// wrapped in an optional; otherwise return std::nullopt. Complete the function.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <map>
#include <optional>
#include <string>

std::optional<int> lookup(const std::map<std::string, int>& table,
                          const std::string& key) {
    // TODO: if the map contains `key`, return its value in an optional.
    // Otherwise return std::nullopt.
    return std::nullopt;
}

CPPLINGS_TEST(optional_lookup) {
    std::map<std::string, int> ages = {
        {"Ada", 36},
        {"Grace", 45},
    };

    std::optional<int> found = lookup(ages, "Ada");
    CPPLINGS_ASSERT(found.has_value());
    CPPLINGS_ASSERT_EQ(*found, 36);

    std::optional<int> missing = lookup(ages, "Nobody");
    CPPLINGS_ASSERT_FALSE(missing.has_value());
}
