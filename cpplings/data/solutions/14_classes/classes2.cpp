// A constructor initializes an object when it is created.

#include "cpplings_test.hpp"

class Account {
    int balance_ = 0;

public:
    Account(int initial) : balance_(initial) {}

    int balance() const {
        return balance_;
    }
};

CPPLINGS_TEST(initial_balance) {
    Account a{100};
    CPPLINGS_ASSERT_EQ(a.balance(), 100);
}
