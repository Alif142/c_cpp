#include <stdio.h>
int checkPerfect(int n){
    int sum = 0;
    for (int i = 1;i<n;i++) {
        if (n % i == 0) {
            sum +=i; 
        } 
    }
    if (n == sum) {
        return 1; 
    }
    else {
        return 0;
    }
}
int main(){
    int arr[100];
    int size;
    printf("Enter size");
    scanf("%d",&size);
    printf("\nEnter elements\n");

    for (int i=0;i<size;i++) {
        printf("arr[%d]",i);
        scanf("%d",&arr[i]);
    }

    int perf[100];

    int j = 0;
    int perfSize = 0;
    for (int i =0;i<size;i++) {
        if (checkPerfect(arr[i]) == 1) {
            perf[j] = arr[i]; 
            j++;
            perfSize++;
        }
    
    }
    printf("Perfect array:\n");
    for (int i=0;i<perfSize;i++) {
        printf("%d ",perf[i]);
    }

}

