// Templates power the standard library. std::vector<T> is a class template.

#include "cpplings_test.hpp"
#include <vector>
#include <string>

template <typename T>
T first(const std::vector<T>& v) {
    return v.front();
}

CPPLINGS_TEST(first_int) {
    std::vector<int> v = {10, 20, 30};
    CPPLINGS_ASSERT_EQ(first(v), 10);
}

CPPLINGS_TEST(first_string) {
    std::vector<std::string> v = {"a", "b"};
    CPPLINGS_ASSERT_EQ(first(v), std::string("a"));
}
