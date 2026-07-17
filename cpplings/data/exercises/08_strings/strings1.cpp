// std::string holds text and supports concatenation with +.
//
// TODO: Build the greeting "Hello, World" by concatenating the two parts so
// the test passes.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>

CPPLINGS_TEST(concatenation) {
    std::string hello = "Hello, ";
    std::string who = "World";
    std::string greeting = hello;  // TODO: also append `who`
    CPPLINGS_ASSERT_EQ(greeting, std::string("Hello, World"));
}
