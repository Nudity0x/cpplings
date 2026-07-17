#include "cpplings_test.hpp"
#include <optional>
#include <string>
#include <variant>
#include <vector>

using Token = std::variant<int, std::string>;

std::optional<int> evaluate(const std::vector<Token>& tokens) {
    int acc = 0;
    std::string op = "+";
    for (const Token& token : tokens) {
        if (std::holds_alternative<std::string>(token)) {
            const std::string& symbol = std::get<std::string>(token);
            if (symbol != "+" && symbol != "*") {
                return std::nullopt;
            }
            op = symbol;
        } else {
            int value = std::get<int>(token);
            if (op == "+") {
                acc += value;
            } else {
                acc *= value;
            }
        }
    }
    return acc;
}

CPPLINGS_TEST(evaluates_token_program) {
    // 0 + 2 * 5 + 1  =>  ((0 + 2) * 5) + 1 = 11
    std::vector<Token> program = {
        2, std::string("*"), 5, std::string("+"), 1};
    std::optional<int> result = evaluate(program);
    CPPLINGS_ASSERT(result.has_value());
    CPPLINGS_ASSERT_EQ(result.value(), 11);

    // A bare value with no operator just adds (implicit leading "+").
    std::vector<Token> single = {42};
    CPPLINGS_ASSERT_EQ(evaluate(single).value_or(-1), 42);

    // An unknown operator is malformed.
    std::vector<Token> bad = {2, std::string("?"), 3};
    CPPLINGS_ASSERT_FALSE(evaluate(bad).has_value());
}
