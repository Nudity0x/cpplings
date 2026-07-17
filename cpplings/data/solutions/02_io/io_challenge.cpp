#include "cpplings_test.hpp"
#include <string>

std::string format_receipt(const std::string& name, int quantity, int cents) {
    int total = quantity * cents;
    return name + " x" + std::to_string(quantity) + " = " + std::to_string(total) + "c";
}

CPPLINGS_TEST(formats_a_receipt) {
    CPPLINGS_ASSERT_EQ(format_receipt("pen", 3, 50), std::string("pen x3 = 150c"));
    CPPLINGS_ASSERT_EQ(format_receipt("mug", 1, 799), std::string("mug x1 = 799c"));
}
