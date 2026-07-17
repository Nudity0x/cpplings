// optional::value_or(fallback) returns the contained value, or the fallback if
// the optional is empty. It's a clean way to supply a default.
//
// TODO: `config_or_default` should return the optional's value if present, or
// the given `fallback` otherwise. Use value_or. The test tries both cases.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <optional>

int config_or_default(std::optional<int> setting, int fallback) {
    // TODO: return the setting if it has a value, else fallback.
    return 0;
}

CPPLINGS_TEST(uses_default_when_empty) {
    CPPLINGS_ASSERT_EQ(config_or_default(std::optional<int>(42), 7), 42);
    CPPLINGS_ASSERT_EQ(config_or_default(std::nullopt, 7), 7);
}
