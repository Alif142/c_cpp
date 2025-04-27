#include <stdio.h>
int main(){
    char c[100];
    printf("Enter a string");
    scanf("%s",c);

    char c2[100];
    int lenC = 0;
    while(c[lenC] != '\0'){
        lenC++;
    }
    int j = 0;
    for (int i = lenC-1; i>=0;i--) {
       c2[j] = c[i];  
       j++;
    }
    c2[j] = '\0';
    int isPalindrome = 1;
    for (int i = 0; i < lenC; i++) {
        if (c[i] != c2[i]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome) {
        printf("palindrom"); 
    }
    else {
        printf("Not palindrom");
    }
}
