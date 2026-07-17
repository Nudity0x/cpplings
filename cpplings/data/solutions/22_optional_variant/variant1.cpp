#include "cpplings_test.hpp"
#include <variant>
#include <string>

int describe(const std::variant<int, std::string>& value) {
    if (std::holds_alternative<int>(value)) {
        return 1;
    }
    return 2;
}

CPPLINGS_TEST(variant_type_query) {
    std::variant<int, std::string> a = 10;
    std::variant<int, std::string> b = std::string("hello");

    CPPLINGS_ASSERT_EQ(describe(a), 1);
    CPPLINGS_ASSERT_EQ(describe(b), 2);
}
