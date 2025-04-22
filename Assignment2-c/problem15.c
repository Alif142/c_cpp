#include <stdio.h>
#include <string.h>
struct Student{
    int id;
    float cgpa;
    int age;
    char fname[10];
    char lname[10];
    char gender[10];
    char contactNum[15];
    char address[30];
};
void display(struct Student s[], int n){
    for (int i=0;i<n;i++) {
        if (s[i].cgpa > 3.5) {
            printf("Info for student %d\n",i+1);
            printf("ID:%d\n",s[i].id); 
            printf("Name:%s %s\n",s[i].fname , s[i].lname);
            printf("Contact:%s\n",s[i].contactNum);
        }
    } 
}

void insert(struct Student s[] , int *n){
    struct Student newStudent;
    printf("Enter new students id:");
    scanf("%d",&newStudent.id);
    printf("Enter new students first name:");
    scanf("%s",newStudent.fname);
    printf("Enter new students last name:");
    scanf("%s",newStudent.lname);
    printf("Enter new students age:");
    scanf("%d",&newStudent.age);
    printf("Enter new students cgpa:");
    scanf("%f",&newStudent.cgpa);
    printf("Enter new students gender:");
    scanf("%s",newStudent.gender);
    printf("Enter new students contact num:");
    scanf("%s",newStudent.contactNum);
    printf("Enter new students address:");
    scanf("%s",newStudent.address);
    s[*n] = newStudent;
    (*n)++;
}

void delete(struct Student s[] , int *n , char fname[] , char lname[]){
   for (int i=0;i<*n;i++) {
        if ((strcmp(s[i].fname,fname)) == 0 && (strcmp(s[i].lname,lname)) == 0) {
            for (int j = i;j<*n;j++) {
                s[j] = s[j + 1]; 
            } 
            (*n)--;
            break;
        }
    } 
}


void modify(struct Student s[] , int id , int n){
    int choice;
    char contact[20];
    char address[30];
    printf("Enter 1 to edit contact or 2 to edit address:");
    scanf("%d",&choice);

    if (choice == 1) {
        printf("Enter new contact:"); 
        scanf("%s",contact);
        for (int i=0;i<n;i++) {
            if (s[i].id == id) {
                strcpy(s[i].contactNum,contact);
            } 
            break;
        }
    }
    if (choice == 2) {
        printf("Enter new address:"); 
        scanf("%s",address);
        for (int i=0;i<n;i++) {
            if (s[i].id == id) {
                strcpy(s[i].address,contact);
            } 
            break;
        }
    }

}


int main(){
    struct Student arr[100]; 
    int n ;
    printf("Enter the number of students you want to add:");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        printf("Info for student %d\n",i+1);
        printf("Enter new students id:");
        scanf("%d",&arr[i].id);
        printf("Enter new students first name:");
        scanf("%s",arr[i].fname);
        printf("Enter new students last name:");
        scanf("%s",arr[i].lname);
        printf("Enter new students age:");
        scanf("%d",&arr[i].age);
        printf("Enter new students cgpa:");
        scanf("%f",&arr[i].cgpa);
        printf("Enter new students gender:");
        scanf("%s",arr[i].gender);
        printf("Enter new students contact num:");
        scanf("%s",arr[i].contactNum);
        printf("Enter new students address:");
        scanf("%s",arr[i].address);
    }

    insert(arr,&n);
    display(arr,n);
    delete(arr,&n,"Sheikh","Ruhan");
    display(arr,n);
    modify(arr,2222258,n);
    display(arr,n);
    printf("\n");
    display(arr,n);
}
