#include <stdio.h>
int palFunc(int n){
    int temp = n , newNum = 0 ,rem = 0;
    while(temp >0){
        rem = temp%10;
        newNum = newNum * 10 +rem;
        temp = temp /10;
    }

    if(n == newNum){
        return 1;
    }
    else {
        return 0;
    }
}
int main(){
    int n,count=0,i=0;
    printf("Enter how many palindrom numbers you want:");
    scanf("%d",&n);
    while (1) {
        if(palFunc(i) == 1){
            printf("%d\n",i);
            count++;
        }
        i++;
        if(count == n) 
            break;
    }
}
