#include <stdio.h>

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
    char arr[20] = "Hello World";
    printf("Length:%d",findlength(arr));
}


