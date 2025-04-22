
#include <stdio.h>
int main(){
    int arr[100];
    int size;
    printf("input the number of elements to be stored in array:");
    scanf("%d",&size);

    for (int i=0;i<size;i++) {
        printf("arr[%d]:",i);
        scanf("%d",&arr[i]);
        printf("\n");
    }
    printf("Given array\n");
    for (int i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }

    int count = 0;
    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if (arr[i] == arr[j]) {
                count++; 
                break;
            } 
        } 
    }
    printf("Total number of duplicate element found in array:%d",count);
}
