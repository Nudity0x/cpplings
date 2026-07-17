// C++ can *move* resources instead of copying them. A moved-from object is
// left in a valid but unspecified state, and no expensive copy happens.
//
// std::move casts a value to an rvalue reference, enabling a move.
//
// TODO: `take` should receive the vector by value. Call it using std::move so
// the caller's vector is moved in (not copied). The test checks the moved-in
// vector still has the right contents.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <vector>
#include <utility>

int sum(std::vector<int> v) {
    int total = 0;
    for (int x : v) {
        total += x;
    }
    return total;
}

CPPLINGS_TEST(move_into_function) {
    std::vector<int> numbers = {1, 2, 3, 4};
    // TODO: pass `numbers` into sum() using std::move.
    int result = sum(numbers);
    CPPLINGS_ASSERT_EQ(result, 10);
}
