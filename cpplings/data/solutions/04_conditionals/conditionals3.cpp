// switch branches on an integral value. Don't forget `break`.

#include "cpplings_test.hpp"
#include <string>

std::string name_of(int n) {
    std::string result;
    switch (n) {
        case 1:
            result = "one";
            break;
        case 2:
            result = "two";
            break;
        default:
            result = "many";
    }
    return result;
}

CPPLINGS_TEST(switch_names) {
    CPPLINGS_ASSERT_EQ(name_of(1), std::string("one"));
    CPPLINGS_ASSERT_EQ(name_of(2), std::string("two"));
    CPPLINGS_ASSERT_EQ(name_of(9), std::string("many"));
}
