// You can read values from an input stream with >>.
//
// TODO: Read two ints from the stream into `x` and `y` using >>, so the test
// sees x == 10 and y == 20.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <sstream>

CPPLINGS_TEST(reads_two_ints) {
    std::istringstream in("10 20");
    int x = 0;
    int y = 0;
    // TODO: read x and y from `in`.

    CPPLINGS_ASSERT_EQ(x, 10);
    CPPLINGS_ASSERT_EQ(y, 20);
}
