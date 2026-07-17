#include "cpplings_test.hpp"

class Employee {
protected:
    int base_salary_;

public:
    explicit Employee(int base_salary) : base_salary_(base_salary) {}

    int annual_pay() const {
        return base_salary_ * 12;
    }
};

class Manager : public Employee {
    int bonus_;

public:
    Manager(int base_salary, int bonus) : Employee(base_salary), bonus_(bonus) {}

    int annual_pay() const {
        return (base_salary_ + bonus_) * 12;
    }
};

CPPLINGS_TEST(inheritance_salary) {
    Employee e(1000);
    CPPLINGS_ASSERT_EQ(e.annual_pay(), 12000);

    Manager m(1000, 500);
    CPPLINGS_ASSERT_EQ(m.annual_pay(), 18000);
}
