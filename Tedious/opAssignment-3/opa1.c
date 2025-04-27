#include <stdio.h>
#include <string.h>

typedef struct  {
   char name[50];
    int id;
    char dept[50];
    double cgpa;


}student;

void printByDept(char *deptName , student allStudent[] , int size){
    for (int i=0;i<size;i++) {
        if (strcmp(allStudent[i].dept,deptName)) {
            printf("Name");
        } 
    }
}
