// QUIZ 1 — combining structs, vectors, and algorithms.
//
// No new concepts here. This pulls together things you've already learned:
// a struct to model data, a vector to hold many of them, and a loop (or an
// STL algorithm) to compute a result.
//
// TODO: `average_score` receives a vector of Students and should return the
// average of their `score` fields, rounded down to an int. Return 0 for an
// empty class. Complete the function.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <vector>

struct Student {
    const char* name;
    int score;
};

int average_score(const std::vector<Student>& students) {
    // TODO: sum every student's score, then divide by the number of students.
    // Return 0 if there are no students (avoid dividing by zero).
    return 0;
}

CPPLINGS_TEST(computes_average) {
    std::vector<Student> class_a = {
        {"Ada", 90},
        {"Linus", 80},
        {"Grace", 100},
    };
    CPPLINGS_ASSERT_EQ(average_score(class_a), 90);

    std::vector<Student> empty;
    CPPLINGS_ASSERT_EQ(average_score(empty), 0);
}
