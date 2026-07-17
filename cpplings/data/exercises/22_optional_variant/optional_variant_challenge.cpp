// CHALLENGE — std::optional + std::variant (sum types, safe absence).
//
// Builds on: this section's optional & variant, vectors (13), strings (08).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: A tiny expression evaluator over a list of "tokens". Each token is
// either an int (a value) or a std::string (an operator: "+" or "*").
//   1. `Token` is a std::variant<int, std::string>.
//   2. `evaluate` folds the tokens left-to-right starting from 0 with an
//      implicit leading "+": walk the list, and whenever you see a string set
//      it as the pending operator; whenever you see an int apply the pending
//      operator ("+" adds, "*" multiplies) to the accumulator.
//   3. If a string token is neither "+" nor "*", return std::nullopt to signal
//      a malformed program. On success return the accumulated int.
// Make the test below read like evaluating a little stack of tokens.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <optional>
#include <string>
#include <variant>
#include <vector>

using Token = std::variant<int, std::string>;

// TODO: std::optional<int> evaluate(const std::vector<Token>& tokens);
std::optional<int> evaluate(const std::vector<Token>& tokens) {
    (void)tokens;
    return std::nullopt;
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
