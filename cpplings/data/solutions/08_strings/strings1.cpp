// std::string holds text and supports concatenation with +.

#include "cpplings_test.hpp"
#include <string>

CPPLINGS_TEST(concatenation) {
    std::string hello = "Hello, ";
    std::string who = "World";
    std::string greeting = hello + who;
    CPPLINGS_ASSERT_EQ(greeting, std::string("Hello, World"));
}
