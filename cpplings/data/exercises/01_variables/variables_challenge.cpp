// CHALLENGE — variables (declarations, types, const, auto).
//
// Builds on: nothing yet — this is the first challenge. It just combines
// everything from this section into one slightly longer problem.
//
// Challenges are the last, hardest exercise in a section. They are longer than
// the others and pull the whole section together. Take your time.
//
// TODO: Compute a shopping total.
//   1. Declare a `const int` `quantity` set to 7.
//   2. Declare a `const double` `unit_price` set to 3.5.
//   3. Use `auto` to declare `subtotal` as quantity * unit_price. Because one
//      operand is a double, `subtotal` deduces to double. (You must cast the
//      int to double explicitly with static_cast to keep the compiler happy
//      under strict warnings.)
//   4. Declare a `const double` `tax_rate` of 0.1 and compute `total` as
//      subtotal plus subtotal * tax_rate.
// The test checks the total is 26.95.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

double shopping_total() {
    // TODO: implement steps 1-4 and return `total`.
    return 0.0;
}

CPPLINGS_TEST(computes_total_with_tax) {
    double total = shopping_total();
    // 7 * 3.5 = 24.5, +10% tax = 26.95
    CPPLINGS_ASSERT(total > 26.94 && total < 26.96);
}
