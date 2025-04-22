#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char arr[100];
    printf("Enter a string:");
    fgets(arr, sizeof(arr), stdin);
    arr[strcspn(arr,"\n")] = '\0';
    int i=0 , j=0;
    while (arr[i] != '\0') {
        if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z' )) {
            arr[j] = arr[i];
            j++;
        } 
        i++;
    }
    arr[j] = '\0';
    printf("%s",arr);
}
