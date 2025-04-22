#include <stdio.h>
#include <stdbool.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, sum = 0;

    while (1) {
        printf("Enter an integer: ");
        scanf("%d", &num);

        if (num < 0) {
            break;
        }

        if (isPrime(num)) {
            printf("%d is Prime, add to sum\n", num);
            sum += num;
        } else {
            printf("%d Not prime\n", num);
        }
    }

    printf("The sum = %d\n", sum);

    return 0;
}
