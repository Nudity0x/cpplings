#include "cpplings_test.hpp"

double shopping_total() {
    const int quantity = 7;
    const double unit_price = 3.5;
    auto subtotal = static_cast<double>(quantity) * unit_price;
    const double tax_rate = 0.1;
    const double total = subtotal + subtotal * tax_rate;
    return total;
}

CPPLINGS_TEST(computes_total_with_tax) {
    double total = shopping_total();
    CPPLINGS_ASSERT(total > 26.94 && total < 26.96);
}
