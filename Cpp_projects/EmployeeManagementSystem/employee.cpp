#include "employee.h"
Employee::Employee(){};
Employee::Employee(int id, string name, double salary)
{
    this->id = id;
    this->name = name;
    this->salary = salary;
}

void Employee::setId(int id)
{
    this->id = id;
}

int Employee::getId()
{
    return id;
}

void Employee::setName(string name)
{
    this->name = name;
}

string Employee::getName()
{
    return name;
}

void Employee::setSalary(double salary)
{
    this->salary = salary;
}

double Employee::getSalary()
{
    return salary;
}

void Employee::print() const
{
    cout << "ID: " << id
         << ", Name: " << name
         << ", Salary: " << salary
         << endl;
}

bool Employee::operator>(const Employee& other) const
{
    return id > other.id;
}

bool Employee::operator<(const Employee& other) const
{
    return id < other.id;
}

bool Employee::operator==(const Employee& other) const
{
    return id == other.id;
}
