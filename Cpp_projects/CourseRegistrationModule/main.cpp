#include <iostream>
#include "functions.h"
using namespace std;

int main() {
    int choice;
    do {
        cout << "\n--- Course Registration System ---\n";
        cout << "1. Admin: Add Course\n2. Admin: Update Course\n3. Admin: Drop Course\n4. Admin: Register Student\n";
        cout << "5. Admin: Drop Student from Course\n6. Student Login\n7. Admin View Reports\n8. Exit\n";
        cout << "Select: "; cin >> choice;
        switch(choice) {
            case 1: addCourse(); break;
            case 2: updateCourse(); break;
            case 3: dropCourse(); break;
            case 4: registerStudent(); break;
            case 5: dropStudentFromCourseAdmin(); break;
            case 6: studentLogin(); break;
            case 7: adminView(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 8);
    return 0;
}
