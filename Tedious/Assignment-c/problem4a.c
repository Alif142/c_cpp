#include <stdio.h>
int main() {
    int age;
    printf("Enter age:");
    scanf("%d",&age);

    if(age>=1 && age <=14){
    printf("Children");
    }
    
    else if(age>=15 && age <=24){
    printf("Early working age");
    }
    
    else if(age>=25 && age <=54){
    printf("Prime working age");
    }
     
    else if(age>=55 && age <=64){
    printf("Mature working age");
    }

     
    else if(age>=65){
    printf("Elderly");
    }
    else {
    printf("Invalid input");
    }
}
