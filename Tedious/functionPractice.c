#include <math.h>
#include <stdio.h>
#include <stdbool.h>
bool isPrime(int n){
    if (n <= 1) {
        return false;
    }
//    else if (n == 2) {
//        return true; 
//    }
    else if (n > 1) {
        for (int i=2; i<n;i++ ) {
            if (n % i == 0) {
                return false; 
            } 
        }
    }
    return true;
}

int seriesSum(int n){
    int sum = 0;
    for (int i=0; i<=n;i++ ) {
        sum+= (i*i); 
    }
    return sum;
}

int getPow(int m , int n){
    int res = 1;
    for (int i=1; i<=n;i++) {
        res*=m;
    }
    return res;
}

int rev(int n){
    int temp = n;
    int rem;
    int rev=0;
    while (temp !=0) {
        rem = temp % 10;
        rev = rev*10 + rem;
        temp = temp / 10;
    }
    return rev;
}

int calcFact(int n){
    int fact = 1;
    for (int i=1;i<=n;i++) {
        fact = fact * i; 
    }
    return fact;
}

float calcCombination(int n , int r){
    float comb = 1;
    comb = (calcFact(n)/ 1.0)/((calcFact(r) * calcFact(n - r))/1.0);
    return comb;
}

void printPrime(int m , int n){
    int prime;
    for (int i=m;i<=n;i++) {
        if (isPrime(i)) {
            printf("%d ",i); 
        }
    }
}

int main()
{
    printPrime(1,15);
}
