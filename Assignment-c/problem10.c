#include <math.h>
#include <stdio.h>
int main() {
     double sum = 0.0;
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        double numerator = pow(i, 6) + i;
        double denominator = pow(i * i, i);
        double term = numerator / denominator;
        sum += term;
    }
    printf("%f",sum);
}
