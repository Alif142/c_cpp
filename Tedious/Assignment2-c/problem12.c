#include <stdio.h>
int main(){
    char arr1[100];
    char arr2[50];
    printf("Enter array1:");
    scanf("%s",arr1);
    printf("Enter array2:");
    scanf("%s",arr2);
    int lenA = 0 , lenB = 0;

    while (arr1[lenA] != '\0') {
        lenA++; 
    }
    int j = 0;
    while (arr1[lenB] != '\0') {
        lenB++; 
        j++;
    }

    for (int i=0;i<lenB;i++) {
        arr1[lenA+i] = arr2[i]; 
    }

    printf("%s",arr1);
}
