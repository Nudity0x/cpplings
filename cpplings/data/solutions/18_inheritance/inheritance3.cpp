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
        balance += balance * rate_percent / 100;
    }
};

CPPLINGS_TEST(savings_earns_interest) {
    SavingsAccount acct;
    acct.deposit(1000);
    acct.add_interest(5);
    CPPLINGS_ASSERT_EQ(acct.get_balance(), 1050);
}
