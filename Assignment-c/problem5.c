#include <stdio.h>
int main(){
char ch;
printf("Enter a character:");
scanf("%c",&ch);

    if(ch >= 'a' && ch<='z'){
        printf("Lower case");
    }


    else if(ch >= 'A' && ch<='z'){
        printf("Uppercase");
    }

    else if(ch >= '0' && ch <='9') {
        printf("Number");
    }

    else {
        printf("Symbol");
    }






}
