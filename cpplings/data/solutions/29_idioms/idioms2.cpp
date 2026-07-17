#include "cpplings_test.hpp"

class Guard {
    int* count_;
public:
    explicit Guard(int* count) : count_(count) { ++(*count_); }

    Guard(const Guard&) = delete;
    Guard& operator=(const Guard&) = delete;

    ~Guard() { --(*count_); }
};

CPPLINGS_TEST(raii_balances_the_count) {
    int active = 0;

    {
        Guard g(&active);
        CPPLINGS_ASSERT_EQ(active, 1);

        {
            Guard nested(&active);
            CPPLINGS_ASSERT_EQ(active, 2);
        }

        CPPLINGS_ASSERT_EQ(active, 1);
    }

    CPPLINGS_ASSERT_EQ(active, 0);
}
