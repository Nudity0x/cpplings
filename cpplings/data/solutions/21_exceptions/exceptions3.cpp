#include "cpplings_test.hpp"
#include <stdexcept>
#include <string>

class NegativeError : public std::runtime_error {
public:
    explicit NegativeError(const std::string& message)
        : std::runtime_error(message) {}
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
