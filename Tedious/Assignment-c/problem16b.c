#include <stdio.h>
int main(){
    for (int i=1; i<=5; i++) {
        for (int j=1; j<=5-i; j++) {
                printf(" ");
        }
        for (int j=1; j<=2*i-1; j++) {
            if(j == 1 || j == 2*i-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }    
    for (int i=4; i>=1; i--) {
        for (int j=1; j<=5-i; j++) {
                printf(" ");
        }
        for (int j=1; j<=2*i-1; j++) {
            if(j == 1 || j == 2*i-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }    
}

//i = 1 j = 5 i = 2 j = 4
