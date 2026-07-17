#include "cpplings_test.hpp"

void reverse_in_place(int* data, int size) {
    if (data == nullptr || size <= 1) {
        return;
    }
    int* front = data;
    int* back = data + (size - 1);
    while (front < back) {
        int tmp = *front;
        *front = *back;
        *back = tmp;
        ++front;
        --back;
    }
}

CPPLINGS_TEST(reverses_with_pointers) {
    int a[] = {1, 2, 3, 4, 5};
    reverse_in_place(a, 5);
    CPPLINGS_ASSERT_EQ(a[0], 5);
    CPPLINGS_ASSERT_EQ(a[1], 4);
    CPPLINGS_ASSERT_EQ(a[2], 3);
    CPPLINGS_ASSERT_EQ(a[3], 2);
    CPPLINGS_ASSERT_EQ(a[4], 1);

    int b[] = {10, 20};
    reverse_in_place(b, 2);
    CPPLINGS_ASSERT_EQ(b[0], 20);
    CPPLINGS_ASSERT_EQ(b[1], 10);

    reverse_in_place(nullptr, 0);
    int c[] = {42};
    reverse_in_place(c, 1);
    CPPLINGS_ASSERT_EQ(c[0], 42);
}
