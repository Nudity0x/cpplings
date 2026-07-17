#include "cpplings_test.hpp"
#include <optional>

int config_or_default(std::optional<int> setting, int fallback) {
    return setting.value_or(fallback);
}

CPPLINGS_TEST(uses_default_when_empty) {
    CPPLINGS_ASSERT_EQ(config_or_default(std::optional<int>(42), 7), 42);
    CPPLINGS_ASSERT_EQ(config_or_default(std::nullopt, 7), 7);
}
