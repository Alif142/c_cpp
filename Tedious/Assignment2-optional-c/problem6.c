#include <stdio.h>
int main(){
    char arr[] = "Bangladesh";
    int count = 0;
    int i=0;
    while (arr[i] != '\0') {
        if (arr[i] == ' ' || arr[i] == '\0') {
            count++; 
        }
    }
    printf("%d",count);
}
