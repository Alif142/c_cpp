#include <iostream>
#include <string>
#include "functions.h"
#include "unsortedtype.h"
using namespace std;

static UnsortedType<Course> courseList;
static UnsortedType<Student> studentList;

static Student findStudentByID(int id, bool &found) {
    studentList.Reset();
    Student s;
    for (int i = 0; i < studentList.Length(); ++i) {
        studentList.GetNext(s);
        if (s.GetID() == id) { found = true; return s; }
    }
    found = false;
    return Student();
}

static Course findCourseByID(const string &id, bool &found) {
    courseList.Reset();
    Course c;
    for (int i = 0; i < courseList.Length(); ++i) {
        courseList.GetNext(c);
        if (c.GetID() == id) { found = true; return c; }
    }
    found = false;
    return Course();
}

void addCourse() {
    string id, title;
    int credit, capacity;
    cout << "Course ID: "; cin >> id;
    cout << "Title: "; cin.ignore(); getline(cin, title);
    cout << "Credit Hour: "; cin >> credit;
    cout << "Max Capacity: "; cin >> capacity;
    courseList.Insert(Course(id, title, credit, capacity));
}

void updateCourse() {
    string id; bool found;
    cout << "Enter Course ID to update: "; cin >> id;
    Course c = findCourseByID(id, found);
    if (!found) { cout << "Course not found.\n"; return; }
    string title; int credit, cap;
    cout << "New Title: "; cin.ignore(); getline(cin, title);
    cout << "New Credit Hour: "; cin >> credit;
    cout << "New Max Capacity: "; cin >> cap;
    c.SetTitle(title);
    c.SetCreditHour(credit);
    c.SetMaxCapacity(cap);
    courseList.Delete(c);
    courseList.Insert(c);
}

void dropCourse() {
    string id; bool found;
    cout << "Enter Course ID to drop: "; cin >> id;
    Course c = findCourseByID(id, found);
    if (!found) { cout << "Course not found.\n"; return; }
    courseList.Delete(c);
}

void registerStudent() {
    int id; string name, email;
    cout << "Student ID: "; cin >> id;
    cout << "Name: "; cin.ignore(); getline(cin, name);
    cout << "Email: "; getline(cin, email);
    studentList.Insert(Student(id, name, email));
}

void dropStudentFromCourseAdmin() {
    int sid; string cid; bool sf;
    cout << "Student ID: "; cin >> sid;
    Student s = findStudentByID(sid, sf);
    if (!sf) { cout << "Student not found.\n"; return; }
    cout << "Course ID: "; cin >> cid;
    Course c = findCourseByID(cid, sf);
    if (!sf) { cout << "Course not found.\n"; return; }
    s.GetCourses().Delete(c);
    studentList.Delete(s);
    studentList.Insert(s);
    c.DecrementEnrollment();
    courseList.Delete(c);
    courseList.Insert(c);
    cout << "Dropped student from course.\n";
}

void studentLogin() {
    int sid; bool found;
    cout << "Enter Student ID: "; cin >> sid;
    Student s = findStudentByID(sid, found);
    if (!found) { cout << "Student not found.\n"; return; }
    int choice;
    do {
        cout << "\n1. Register for a Course\n2. Drop a Course\n3. View Registered Courses\n4. Logout\nSelect: ";
        cin >> choice;
        if (choice == 1) {
            string cid; bool cf;
            cout << "Enter Course ID: "; cin >> cid;
            Course c = findCourseByID(cid, cf);
            if (!cf) { cout << "Course not found.\n"; continue; }
            if (c.GetEnrolledCount() >= c.GetMaxCapacity()) {
                cout << "Course full.\n"; continue;
            }
            bool already;
            s.GetCourses().Search(c, already);
            if (already) { cout << "Already registered.\n"; continue; }
            s.GetCourses().Insert(c);
            c.IncrementEnrollment();
            courseList.Delete(c);
            courseList.Insert(c);
            studentList.Delete(s);
            studentList.Insert(s);
        } else if (choice == 2) {
            string cid; cout << "Enter Course ID to drop: "; cin >> cid;
            Course c(cid, "", 0, 0);
            s.GetCourses().Delete(c);
            c.DecrementEnrollment();
            courseList.Delete(c);
            courseList.Insert(c);
            studentList.Delete(s);
            studentList.Insert(s);
        } else if (choice == 3) {
            Course c; s.GetCourses().Reset();
            for (int i = 0; i < s.GetCourses().Length(); ++i) {
                s.GetCourses().GetNext(c);
                cout << c.GetID() << " - " << c.GetTitle() << "\n";
            }
        }
    } while (choice != 4);
}

void adminView() {
    int choice;
    cout << "\n1. List all students with courses\n2. List all courses with enrollment count\n3. List students of a particular course\nSelect: ";
    cin >> choice;
    if (choice == 1) {
        Student s; Course c;
        studentList.Reset();
        for (int i = 0; i < studentList.Length(); ++i) {
            studentList.GetNext(s);
            cout << s.GetID() << " - " << s.GetName() << "\n";
            s.GetCourses().Reset();
            for (int j = 0; j < s.GetCourses().Length(); ++j) {
                s.GetCourses().GetNext(c);
                cout << "  * " << c.GetID() << " " << c.GetTitle() << "\n";
            }
        }
    } else if (choice == 2) {
        Course c;
        courseList.Reset();
        for (int i = 0; i < courseList.Length(); ++i) {
            courseList.GetNext(c);
            cout << c.GetID() << " (" << c.GetEnrolledCount() << "/" << c.GetMaxCapacity() << ")\n";
        }
    } else if (choice == 3) {
        string cid; bool cf; cout << "Enter Course ID: "; cin >> cid;
        Course c = findCourseByID(cid, cf);
        if (!cf) { cout << "Course not found.\n"; return; }
        Student s;
        cout << "Students in " << cid << ":\n";
        studentList.Reset();
        for (int i = 0; i < studentList.Length(); ++i) {
            studentList.GetNext(s);
            bool enrolled;
            s.GetCourses().Search(c, enrolled);
            if (enrolled) cout << "  - " << s.GetID() << " " << s.GetName() << "\n";
        }
    }
}
