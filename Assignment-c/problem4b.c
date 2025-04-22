#include <stdio.h>
int main() {
    int age;
    int cases;
    printf("Enter age:");
    scanf("%d", &age);

    switch (age) {

        case 1 ... 14:
            printf("Child");
            break;

        case 15 ... 24:
            printf("Early working age");
            break;

        case 25 ... 54:
            printf("Prime working age");
            break;

        case 55 ... 64:
            printf("Mature working age");
            break;

        default:
            printf("Elderly");
    }

}
