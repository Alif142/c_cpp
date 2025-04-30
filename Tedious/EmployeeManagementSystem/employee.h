#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class Employee
{
public:
    Employee();
    Employee(int id, string name, double salary);
    void setId(int id);
    int getId();
    void setName(string name);
    string getName();
    void setSalary(double salary);
    double getSalary();
    void print() const;
    bool operator>(const Employee& other) const;
    bool operator<(const Employee& other) const;
    bool operator==(const Employee& other) const;

private:
    int id;
    string name;
    double salary;
};

#endif // EMPLOYEE_H
