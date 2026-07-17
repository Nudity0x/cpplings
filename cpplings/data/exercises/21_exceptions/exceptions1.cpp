// Exceptions signal errors that can't be handled locally. You `throw` a value
// and a matching `catch` block up the call stack handles it. Use try/catch:
//   try { risky(); } catch (const std::exception& e) { ... }
//
// TODO: `safe_divide` should throw std::runtime_error when the divisor is 0.
// Complete it so the test's catch block runs for a zero divisor and normal
// division works otherwise.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <stdexcept>

int safe_divide(int a, int b) {
    // TODO: if b == 0, throw std::runtime_error("divide by zero").
    return a / b;
}

CPPLINGS_TEST(throws_on_zero) {
    CPPLINGS_ASSERT_EQ(safe_divide(10, 2), 5);

    bool threw = false;
    try {
        safe_divide(1, 0);
    } catch (const std::runtime_error&) {
        threw = true;
    }
    CPPLINGS_ASSERT(threw);
}
