#include <stdio.h>
int main() {
  float salary, tax;

  printf("Enter salary:");
  scanf("%f", &salary);

  if (salary >= 0 && salary <= 14999.99) {
    tax = (15 / 100.0) * (salary - 0.00);
  }

  else if (salary >= 15000.00 && salary <= 29999.99) {
    tax = 2250.00 + ((18 / 100.0) * (salary - 15000.00));
  }

  else if (salary >= 30000.00 && salary <= 49999.99) {
    tax = 5400.00 + ((22 / 100.0) * (salary - 30000.00));
  }

  else if (salary >= 50000.00 && salary <= 79999.99) {
    tax = 11000.00 + ((27 / 100.0) * (salary - 50000.00));
  }

  else if (salary >= 80000.00 && salary <= 150000.00) {
    tax = 21000.00 + ((33 / 100.0) * (salary - 80000.00));
  }

  else {
    printf("Wrong input...");
  }

    printf("Tax: %f",tax);
}
