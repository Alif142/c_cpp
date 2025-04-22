#include <stdio.h>
void Replace (char arr[], char oldChar, char newChar){
    int i=0;
    while (arr[i] != '\0') {
        if (arr[i] == oldChar) {
           arr[i] = newChar; 
        } 
        i++;
    }
}
int main(){
    char arr[100];
    char oldChar , newChar;
    printf("Enter a string:");
    scanf("%s",arr);
    getchar();
    printf("Enter old char:");
    scanf("%c",&oldChar);
    getchar();
    printf("Enter new char:");
    scanf("%c",&newChar);

    Replace(arr,oldChar,newChar);

    printf("New String: %s",arr);
}
