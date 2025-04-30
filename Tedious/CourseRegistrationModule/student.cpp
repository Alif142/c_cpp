#include "student.h"

Student::Student() : studentID(0), name(""), email("") {}
Student::Student(int id, const string &name, const string &email)
    : studentID(id), name(name), email(email) {}

int Student::GetID() const { return studentID; }
string Student::GetName() const { return name; }
string Student::GetEmail() const { return email; }
UnsortedType<Course>& Student::GetCourses() { return registeredCourses; }

bool Student::operator==(const Student &other) const {
    return studentID == other.studentID;
}
