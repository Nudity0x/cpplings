// A class template parameterizes a whole type over one or more type params.
//
// TODO: Complete the `Pair<T>` template so it stores two values of type T and
// exposes `first()` and `second()`. The test uses Pair<int>.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

template <typename T>
class Pair {
private:
    T a_;
    T b_;

public:
    Pair(T a, T b) : a_(a), b_(b) {}

    // TODO: add `T first() const` and `T second() const`.
};

CPPLINGS_TEST(stores_two_values) {
    Pair<int> p(3, 7);
    CPPLINGS_ASSERT_EQ(p.first(), 3);
    CPPLINGS_ASSERT_EQ(p.second(), 7);
}
