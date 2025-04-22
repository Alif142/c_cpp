#include <iostream>
#include "employee.h"
#include "sortedtype.cpp"

using namespace std;

void displayMenu()
{
    cout << "\nEmployee Management System" << endl;
    cout << "1. Insert Employee" << endl;
    cout << "2. Delete Employee" << endl;
    cout << "3. Search Employee" << endl;
    cout << "4. Print All Employees" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    SortedType<Employee> list;
    int choice;
    do
    {
        displayMenu();
        cin >> choice;
        switch(choice)
        {
        case 1:
        {
            int id;
            string name;
            double salary;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Salary: ";
            cin >> salary;
            list.Insert(Employee(id, name, salary));
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            list.Delete(Employee(id, "", 0));
            break;
        }
        case 3:
        {
            int id;
            bool found;
            cout << "Enter ID to search: ";
            cin >> id;
            list.Search(Employee(id, "", 0), found);
            if(found)
                cout << "Employee with ID " << id << " found." << endl;
            else
                cout << "Employee with ID " << id << " not found." << endl;
            break;
        }
        case 4:
        {
            list.Reset();
            int len = list.Length();
            cout << "\nAll Employees:" << endl;
            for(int i = 0; i < len; i++)
            {
                Employee e(0, "", 0);
                list.GetNext(e);
                e.print();
            }
            break;
        }
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }
    while(choice != 5);

    return 0;
}
