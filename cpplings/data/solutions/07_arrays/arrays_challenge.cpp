#include "cpplings_test.hpp"
#include <climits>

int second_largest(const int* arr, int size) {
    int largest = INT_MIN;
    int second = INT_MIN;
    for (int i = 0; i < size; ++i) {
        int v = arr[i];
        if (v > largest) {
            second = largest;
            largest = v;
        } else if (v < largest && v > second) {
            second = v;
        }
    }
    return second;
}

CPPLINGS_TEST(finds_second_largest) {
    int a[] = {3, 7, 1, 9, 4};
    CPPLINGS_ASSERT_EQ(second_largest(a, 5), 7);

    int b[] = {10, 10, 8};
    CPPLINGS_ASSERT_EQ(second_largest(b, 3), 8);

    int c[] = {1, 2};
    CPPLINGS_ASSERT_EQ(second_largest(c, 2), 1);
}
