#include <stdio.h>
int main(){
int n,i=5,j=4 ,sum = 0, numOp = 1 ;
    printf("Enter n:");
    scanf("%d",&n);
    while(numOp <= n ){
       sum+=i*i;
        i +=  j;
        j+=2;
        numOp++;
    }
    printf("%d", sum);
    return 0;

}
