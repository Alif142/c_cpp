#include <stdio.h>
int main(){
    char ch;
    for (int i=5; i>=1; i--) {
        ch = 'A' + i - 1;
        for (int j=1; j<=i; j++) {
            printf("%c",ch); 
            ch--;
        }
        printf("\n");
    }
}
