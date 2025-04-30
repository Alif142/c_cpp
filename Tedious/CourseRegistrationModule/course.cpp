#include "course.h"

Course::Course() : courseID(""), title(""), creditHour(0), maxCapacity(0), enrolledCount(0) {}

Course::Course(const string &id, const string &title, int credit, int capacity)
: courseID(id), title(title), creditHour(credit), maxCapacity(capacity), enrolledCount(0) {}

string Course::GetID() const { return courseID; }
string Course::GetTitle() const { return title; }
int Course::GetCreditHour() const { return creditHour; }
int Course::GetMaxCapacity() const { return maxCapacity; }
int Course::GetEnrolledCount() const { return enrolledCount; }

void Course::SetTitle(const string &t) { title = t; }
void Course::SetCreditHour(int c) { creditHour = c; }
void Course::SetMaxCapacity(int m) { maxCapacity = m; }
void Course::IncrementEnrollment() { ++enrolledCount; }
void Course::DecrementEnrollment() { if (enrolledCount > 0) --enrolledCount; }

bool Course::operator==(const Course &other) const {
    return courseID == other.courseID;
}
