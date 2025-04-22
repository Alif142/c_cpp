#include <stdio.h>

int findlength(char s[]){
    int length=0;
    int i=0;
    while (s[i] != '\0') {
        length++; 
        i++;
    }
    return length;
}

int findlength(char *s){
    int length=0;
    int i=0;
    while (s[i] != '\0') {
        length++; 
        i++;
    }
    return length;
}

int main(){
    char arr[10] = "Alif";
    printf("Length:%d",findlength(arr));
}
