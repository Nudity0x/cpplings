// You can read values from an input stream with >>.

#include "cpplings_test.hpp"
#include <sstream>

CPPLINGS_TEST(reads_two_ints) {
    std::istringstream in("10 20");
    int x = 0;
    int y = 0;
    in >> x >> y;

    CPPLINGS_ASSERT_EQ(x, 10);
    CPPLINGS_ASSERT_EQ(y, 20);
}
