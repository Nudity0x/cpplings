// You can catch an exception and read its message via what(). Standard
// exceptions like std::out_of_range carry a message you pass to the
// constructor.
//
// TODO: `at` should throw std::out_of_range with the message "bad index" when
// `i` is outside 0..size-1. The test catches it and compares e.what().
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <stdexcept>
#include <string>

int at(const int* arr, int size, int i) {
    // TODO: if i < 0 or i >= size, throw std::out_of_range("bad index").
    return arr[i];
}

CPPLINGS_TEST(out_of_range_message) {
    int nums[3] = {10, 20, 30};
    CPPLINGS_ASSERT_EQ(at(nums, 3, 1), 20);

    std::string message;
    try {
        at(nums, 3, 5);
    } catch (const std::out_of_range& e) {
        message = e.what();
    }
    CPPLINGS_ASSERT_EQ(message, std::string("bad index"));
}
