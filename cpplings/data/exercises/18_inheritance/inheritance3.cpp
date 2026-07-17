// `protected` members are accessible to a class and its derived classes, but
// not to outside code. Derived classes can build on protected state.
//
// TODO: `SavingsAccount` should add interest to the protected `balance` it
// inherits from `Account`. Implement `add_interest` to increase balance by
// `balance * rate_percent / 100`. The test deposits, adds interest, checks it.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

class Account {
protected:
    int balance;
public:
    Account() : balance(0) {}
    void deposit(int amount) { balance += amount; }
    int get_balance() const { return balance; }
};

class SavingsAccount : public Account {
public:
    void add_interest(int rate_percent) {
        // TODO: increase balance by balance * rate_percent / 100.
    }
};

CPPLINGS_TEST(savings_earns_interest) {
    SavingsAccount acct;
    acct.deposit(1000);
    acct.add_interest(5);
    CPPLINGS_ASSERT_EQ(acct.get_balance(), 1050);
}
