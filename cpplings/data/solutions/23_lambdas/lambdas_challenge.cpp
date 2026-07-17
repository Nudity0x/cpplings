#include "cpplings_test.hpp"
#include <functional>
#include <vector>

std::function<int(int)> make_adder(int n) {
    return [n](int x) { return x + n; };
}

int apply_all(const std::vector<std::function<int(int)>>& steps, int input) {
    int result = input;
    for (const std::function<int(int)>& step : steps) {
        result = step(result);
    }
    return result;
}

CPPLINGS_TEST(lambda_pipeline) {
    auto add10 = make_adder(10);
    CPPLINGS_ASSERT_EQ(add10(5), 15);

    auto doubler = [](int x) { return x * 2; };

    // 3 -> +10 -> 13 -> *2 -> 26 -> +10 -> 36
    std::vector<std::function<int(int)>> steps = {add10, doubler, add10};
    CPPLINGS_ASSERT_EQ(apply_all(steps, 3), 36);
}
