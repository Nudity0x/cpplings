// switch branches on an integral value. Don't forget `break`.
//
// TODO: This switch falls through because it's missing breaks, so every input
// returns "many". Fix it so 1 -> "one", 2 -> "two", anything else -> "many".
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>

std::string name_of(int n) {
    std::string result;
    switch (n) {
        case 1:
            result = "one";
        case 2:
            result = "two";
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
