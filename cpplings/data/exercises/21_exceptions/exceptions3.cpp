// You can define your own exception type by deriving from std::exception (or
// std::runtime_error) and overriding what(). Catching by base reference lets
// callers handle whole categories of errors.
//
// TODO: Make `NegativeError` derive from std::runtime_error and forward a
// message to its base constructor. `checked_sqrt_input` should throw it when
// given a negative number. The test catches it as std::exception.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <stdexcept>
#include <string>

// TODO: make NegativeError derive from std::runtime_error.
class NegativeError {
};

int checked_sqrt_input(int n) {
    if (n < 0) {
        throw NegativeError("negative input");
    }
    return n;
}

CPPLINGS_TEST(custom_exception_caught_as_base) {
    CPPLINGS_ASSERT_EQ(checked_sqrt_input(9), 9);

    bool caught = false;
    try {
        checked_sqrt_input(-1);
    } catch (const std::exception&) {
        caught = true;
    }
    CPPLINGS_ASSERT(caught);
}
