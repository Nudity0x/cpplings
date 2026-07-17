// CHALLENGE — inheritance (base/derived, constructor chaining, protected).
//
// Builds on: classes (14), conditionals (04), functions (06).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: An `Employee` base stores a monthly `base_salary_` (protected) and
// reports `annual_pay()` = base_salary_ * 12. A `Manager` derives from it and
// adds a monthly `bonus_`; its `annual_pay()` must be
// (base_salary_ + bonus_) * 12.
//
//   1. Give Employee a constructor taking the monthly base salary.
//   2. Give Manager a constructor taking base salary AND bonus; it must forward
//      the base salary to the Employee base constructor and store the bonus.
//   3. Implement both annual_pay() methods. Manager's uses the inherited,
//      protected base_salary_.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

class Employee {
protected:
    int base_salary_;  // monthly, accessible to derived classes

public:
    // TODO: store the monthly base salary in base_salary_.
    explicit Employee(int base_salary) {
        (void)base_salary;
    }

    int annual_pay() const {
        // TODO: return base_salary_ * 12.
        return 0;
    }
};

class Manager : public Employee {
    int bonus_;  // monthly bonus

public:
    // TODO: forward base_salary to the Employee base constructor, store bonus.
    Manager(int base_salary, int bonus) : Employee(base_salary) {
        (void)bonus;
    }

    int annual_pay() const {
        // TODO: return (base_salary_ + bonus_) * 12.
        return 0;
    }
};

CPPLINGS_TEST(inheritance_salary) {
    Employee e(1000);
    CPPLINGS_ASSERT_EQ(e.annual_pay(), 12000);

    Manager m(1000, 500);
    CPPLINGS_ASSERT_EQ(m.annual_pay(), 18000);
}
