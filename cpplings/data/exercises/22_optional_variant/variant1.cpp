// std::variant<A, B, ...> holds exactly one value of one of its listed types.
// Query which type it holds with std::holds_alternative<T>(v), and read it with
// std::get<T>(v). Assigning a value of a listed type switches the active type.
//
// TODO: `describe` receives a variant that is either an int or a std::string.
// Return 1 if it currently holds an int, or 2 if it holds a string. Use
// std::holds_alternative. The test passes both kinds.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <variant>
#include <string>

int describe(const std::variant<int, std::string>& value) {
    // TODO: return 1 if value holds an int, 2 if it holds a std::string.
    return 0;
}

CPPLINGS_TEST(variant_type_query) {
    std::variant<int, std::string> a = 10;
    std::variant<int, std::string> b = std::string("hello");

    CPPLINGS_ASSERT_EQ(describe(a), 1);
    CPPLINGS_ASSERT_EQ(describe(b), 2);
}
