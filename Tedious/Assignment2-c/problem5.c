#include <stdio.h>
int main(){
    int size;
    printf("Enter size:");
    scanf("%d",&size);

    float arr[100];
    for (int i=0; i<size; i++) {
        printf("arr[%d]:",i);
        scanf("%f",&arr[i]);
        printf("\n");
    } 
    float sum,avg;

    for (int i = 0;i<size;i++) {
        sum+=arr[i]; 
    }
    avg = sum/size; 
    printf("Avrage is %.3f",avg);
    printf("\n");
    printf("Numbers greater then the avrage:");
    for (int i=0; i<size;i++) {
        if (arr[i]>avg) {
            printf("%.3f ",arr[i]); 
        } 
    }
}
