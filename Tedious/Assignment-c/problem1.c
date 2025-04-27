#include <stdio.h>
int main() {
  float c, f;
  printf("Enter celcius temperature:");
  scanf("%f", &c);
  f = c * ((float)9/5) + 32;
  printf("Temperature in Fahrenhite: %.2f", f);
    return 0;
}
