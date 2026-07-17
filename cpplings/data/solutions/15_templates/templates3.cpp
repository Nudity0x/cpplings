// A class template parameterizes a whole type over one or more type params.

#include "cpplings_test.hpp"

template <typename T>
class Pair {
private:
    T a_;
    T b_;

public:
    Pair(T a, T b) : a_(a), b_(b) {}

    T first() const {
        return a_;
    }

    T second() const {
        return b_;
    }
};

CPPLINGS_TEST(stores_two_values) {
    Pair<int> p(3, 7);
    CPPLINGS_ASSERT_EQ(p.first(), 3);
    CPPLINGS_ASSERT_EQ(p.second(), 7);
}
