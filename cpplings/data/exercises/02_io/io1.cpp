// std::cout prints to standard output. Values are chained with <<.
//
// TODO: This test builds a string via std::ostringstream (the same streaming
// you use with std::cout). Make it produce "sum = 7" by fixing the expression.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <sstream>

CPPLINGS_TEST(prints_sum) {
    int a = 3;
    int b = 4;
    std::ostringstream out;
    out << "sum = " << a - b;
    CPPLINGS_ASSERT_EQ(out.str(), std::string("sum = 7"));
}
