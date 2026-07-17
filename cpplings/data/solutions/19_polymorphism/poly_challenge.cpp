#include "cpplings_test.hpp"
#include <memory>
#include <vector>

class Shape {
public:
    virtual int area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    int r_;
public:
    explicit Circle(int r) : r_(r) {}
    int area() const override { return 3 * r_ * r_; }
};

class Square : public Shape {
    int s_;
public:
    explicit Square(int s) : s_(s) {}
    int area() const override { return s_ * s_; }
};

int total_area(const std::vector<std::unique_ptr<Shape>>& shapes) {
    int sum = 0;
    for (const auto& shape : shapes) {
        sum += shape->area();
    }
    return sum;
}

CPPLINGS_TEST(polymorphic_total_area) {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(2));  // 3*2*2 = 12
    shapes.push_back(std::make_unique<Square>(5));  // 25
    shapes.push_back(std::make_unique<Circle>(1));  // 3

    CPPLINGS_ASSERT_EQ(total_area(shapes), 40);
}
