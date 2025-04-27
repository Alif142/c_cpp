#include <stdio.h>
int main() {
  int num = 200;
  while (num >= 100) {
    if (num % 8 == 0) {
      printf("%d ", num);
    }
    num--;
  }
}
