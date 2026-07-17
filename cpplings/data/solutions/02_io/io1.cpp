// std::cout prints to standard output. Values are chained with <<.

#include "cpplings_test.hpp"
#include <sstream>

CPPLINGS_TEST(prints_sum) {
    int a = 3;
    int b = 4;
    std::ostringstream out;
    out << "sum = " << a + b;
    CPPLINGS_ASSERT_EQ(out.str(), std::string("sum = 7"));
}
