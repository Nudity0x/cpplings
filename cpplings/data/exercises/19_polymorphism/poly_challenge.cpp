// CHALLENGE — polymorphism (virtual dispatch, abstract base, containers).
//
// Builds on: inheritance (18), smart pointers (17), vectors (13).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: An abstract `Shape` has a pure virtual `area()` and a virtual
// destructor. Implement two derived shapes and one free function:
//   1. `Circle` (radius r_): area() = 3 * r_ * r_  (3 stands in for pi).
//   2. `Square` (side s_):   area() = s_ * s_.
//   3. `total_area(const std::vector<std::unique_ptr<Shape>>&)`: sum the areas
//      via virtual dispatch through the base pointers.
// This is the full polymorphism pattern: abstract interface, concrete overrides,
// owned behind unique_ptr in a vector, dispatched at runtime.
//
// I AM NOT DONE

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
    // TODO: override area() to return 3 * r_ * r_.
};

class Square : public Shape {
    int s_;
public:
    explicit Square(int s) : s_(s) {}
    // TODO: override area() to return s_ * s_.
};

int total_area(const std::vector<std::unique_ptr<Shape>>& shapes) {
    // TODO: sum shape->area() for every shape.
    return 0;
}

CPPLINGS_TEST(polymorphic_total_area) {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(2));  // 3*2*2 = 12
    shapes.push_back(std::make_unique<Square>(5));  // 25
    shapes.push_back(std::make_unique<Circle>(1));  // 3

    CPPLINGS_ASSERT_EQ(total_area(shapes), 40);
}
