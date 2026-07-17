// CHALLENGE — lambdas (captures, closures, higher-order functions).
//
// Builds on: functions (06), vectors (13), references (10), templates (15).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: Build a small pipeline of transformations, each a lambda.
//   1. `make_adder(n)` returns a closure that adds `n` to its argument. It must
//      capture `n` BY VALUE so the returned lambda stays valid after the call.
//   2. `apply_all` takes a vector of int->int functions and an input int, and
//      folds them left-to-right: the output of one feeds the next.
// Complete both so the test composes an adder and a doubler.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <functional>
#include <vector>

// TODO: return a closure (int)->int that adds n, capturing n by value.
std::function<int(int)> make_adder(int n) {
    (void)n;
    return {};
}

int apply_all(const std::vector<std::function<int(int)>>& steps, int input) {
    // TODO: run input through each step in order, returning the final result.
    (void)steps;
    return input;
}

CPPLINGS_TEST(lambda_pipeline) {
    auto add10 = make_adder(10);
    CPPLINGS_ASSERT_EQ(add10(5), 15);

    auto doubler = [](int x) { return x * 2; };

    // 3 -> +10 -> 13 -> *2 -> 26 -> +10 -> 36
    std::vector<std::function<int(int)>> steps = {add10, doubler, add10};
    CPPLINGS_ASSERT_EQ(apply_all(steps, 3), 36);
}
