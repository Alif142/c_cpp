#include <math.h>
#include <stdio.h>
int checkArmstrong(int n){
    int temp = n,rem = 0,newNum = 0;
    while (temp > 0) {
        rem = temp % 10;
        newNum = newNum + pow(rem,3);
        temp = temp / 10;
    }

    if (newNum == n) {
        return 1; 
    }
    else {
        return 0;
    }
}

int main(){
    for (int i = 1; i<= 500; i++) {
        if(checkArmstrong(i) == 1){
        printf("%d ",i);
        }
    }
}

