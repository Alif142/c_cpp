#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course {
private:
    string courseID;
    string title;
    int creditHour;
    int maxCapacity;
    int enrolledCount;
public:
    Course();
    Course(const string &id, const string &title, int credit, int capacity);
    string GetID() const;
    string GetTitle() const;
    int GetCreditHour() const;
    int GetMaxCapacity() const;
    int GetEnrolledCount() const;
    void SetTitle(const string &t);
    void SetCreditHour(int c);
    void SetMaxCapacity(int m);
    void IncrementEnrollment();
    void DecrementEnrollment();
    bool operator==(const Course &other) const;
};

#endif // COURSE_H

