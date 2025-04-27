#include <stdio.h>
#include <limits.h>
#include <string.h>
struct student{
    int ID;
    char fname[20];
    char lname[20];
    int age;
    float cgpa;
};


void printInfo(struct student s1){
    printf("ID:%d\n",s1.ID);
    printf("Name:%s %s\n",s1.fname,s1.lname);
    printf("Age:%d\n",s1.age);
    printf("CGPA:%f\n\n",s1.cgpa);
}


int main(){
    struct student slist[5];
    int size = 5;
    for (int i=0;i<size;i++) {
        printf("\nFor student %d\n\n",i+1);
        printf("Enter id:");
        scanf("%d",&slist[i].ID);
        getchar();
        printf("Enter first name:");
        scanf("%s",slist[i].fname);
        getchar();
        printf("Enter last name:");
        scanf("%s",slist[i].lname);
        getchar();
        printf("Enter age:");
        scanf("%d",&slist[i].age);
        getchar();
        printf("Enter cgpa:");
        scanf("%f",&slist[i].cgpa);
        getchar();
    }

    int id;
    printf("\nEnter id to search for a student:");
    scanf("%d",&id);

printf("\n\n<<<<<<Output>>>>>>\n\n");

    for (int i = 0;i<size;i++) {
        if (slist[i].ID == id) {
            printInfo(slist[i]);
            break;
        } 
    }

    int ys = INT_MAX;

    for (int i=0;i<size;i++) {
        if (slist[i].age < ys) {
            ys = slist[i].age; 
        } 
    }

    for (int i=0;i<size;i++) {
        if (ys == slist[i].age) {
            printf("Youngest student name:%s %s\n\n",slist[i].fname,slist[i].lname);
        } 
    }

    float highCgpa = INT_MIN;
    for (int i=0;i<size;i++) {
        if (slist[i].cgpa > highCgpa) {
            highCgpa = slist[i].cgpa; 
        } 
    }

    printf("\nHighest cgpa student info\n\n");
    for (int i=0;i<size;i++) {
        if (highCgpa == slist[i].cgpa) {
            printInfo(slist[i]);
            break;
        } 
    }

    printf("\nStudents whose first names are not Jhon\n\n");
    for (int i=0;i<size;i++) {
        if (strcmp("Jhon",slist[i].fname) != 0 && strcmp("jhon",slist[i].fname) != 0) {
            printInfo(slist[i]);
        } 
    }

}
