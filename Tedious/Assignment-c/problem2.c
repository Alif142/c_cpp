#include <stdio.h>
int main() {
    int age;
    char sts;
    printf("Enter age :");
    scanf("%d",&age);
    scanf("%c",&sts);
    printf("Enter sts :");
    scanf("%c",&sts);
    if (age > 59) {

        if (sts == 'W') {
            printf("Working senior");
        }

        else {
            printf("Retired senior");
        }

  }

    else {

        {
            if (age > 20) {
                printf("Adult");
            }

            else {
                if (age > 12) {
                    printf("Teen");
                }

                else {
                    printf("Child");
                }
            }
        }
    }
}
