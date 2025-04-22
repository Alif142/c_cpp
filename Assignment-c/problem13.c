#include <stdio.h>
int findpalin(int n){

    int temp = n , newNum = 0 ,rem = 0;
    while(temp >0){
        rem = temp%10;
        newNum = newNum * 10 +rem;
        temp = temp /10;
    }
    if (newNum == n) {
        return newNum; 
    }
    else {
    return 0;
    }
}
int main(){
    int m,n;
    int palindromNum = 0, sum = 0;
    printf("Enter start and end:");
    scanf("%d%d",&m,&n);
    for (int i = m; i<= n; i++){
        if (findpalin(i) != 0) {
            palindromNum = findpalin(i);
            printf("%d ",palindromNum);
            sum+= palindromNum;
        } 
    }
    printf("\nSum:%d",sum);

}
