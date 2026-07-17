// Templates power the standard library. std::vector<T> is a class template.
//
// TODO: Write a template function `first` that returns the first element of a
// std::vector<T>. Fill in the return type and body.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <vector>
#include <string>

template <typename T>
T first(const std::vector<T>& v) {
    // TODO: return the first element
    return T{};
}

CPPLINGS_TEST(first_int) {
    std::vector<int> v = {10, 20, 30};
    CPPLINGS_ASSERT_EQ(first(v), 10);
}

CPPLINGS_TEST(first_string) {
    std::vector<std::string> v = {"a", "b"};
    CPPLINGS_ASSERT_EQ(first(v), std::string("a"));
}
