#include <stdio.h>
int main(){
    int n;
    printf("Enter value of n:");
    scanf("%d",&n);
    int i = 1 , j = 2;
    float sum = 0;

    while(i<=n){
        if (i%2 != 0) {
            sum+= ((float)i/j); 
        }
        else {
            sum-= ((float)i/j); 
        }
        i++;
        j++;
    }

    printf("%f",sum);
}

