#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "unsortedtype.cpp"
#include "course.h"
using namespace std;

class Student {
private:
    int studentID;
    string name;
    string email;
    UnsortedType<Course> registeredCourses;
public:
    Student();
    Student(int id, const string &name, const string &email);
    int GetID() const;
    string GetName() const;
    string GetEmail() const;
    UnsortedType<Course>& GetCourses();
    bool operator==(const Student &other) const;
};

#endif // STUDENT_H
