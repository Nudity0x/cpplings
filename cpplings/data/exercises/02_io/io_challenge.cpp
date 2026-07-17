// CHALLENGE — I/O and string formatting.
//
// Builds on: variables (01).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: `format_receipt` builds a one-line receipt string from an item name, a
// quantity, and a unit price in whole cents. It must return exactly:
//
//     "<name> x<qty> = <total>c"
//
// e.g. format_receipt("pen", 3, 50) -> "pen x3 = 150c".
// Use std::to_string to turn the numbers into text and concatenate with +.
// Compute the total as quantity * cents.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>

std::string format_receipt(const std::string& name, int quantity, int cents) {
    // TODO: build and return the formatted line described above.
    return "";
}

CPPLINGS_TEST(formats_a_receipt) {
    CPPLINGS_ASSERT_EQ(format_receipt("pen", 3, 50), std::string("pen x3 = 150c"));
    CPPLINGS_ASSERT_EQ(format_receipt("mug", 1, 799), std::string("mug x1 = 799c"));
}
