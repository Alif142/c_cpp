#include <stdio.h>
#include <stdlib.h>
int loopFibo(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    int sum = 0;
    int first = 0;
    int second = 1;
    for (int i=3;i<=n;i++) {
        sum = first + second;
        first = second;
        second = sum;
    }
    return sum;
}

int recursionFibo(int n){
    if (n == 0) return 0;
    if (n == 1) return 1; 
    
    return recursionFibo(n-1)+ recursionFibo(n-2);
}

int numSum(int n){
    if (n > 0) {
        return n + numSum(n-1); 
    }
    else
        return 0;
}

int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    printf("%d\n",loopFibo(n));
    printf("%d\n",recursionFibo(6));
    int num = numSum(n);
    printf("%d\n",num);
}
