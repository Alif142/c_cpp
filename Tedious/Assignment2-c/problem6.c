#include <stdio.h>
int main(){
    int arr[100];
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    printf("Enter elements for the array\n");

    for (int i=0;i<size;i++) {
        printf("arr[%d]:",i);
        scanf("%d",&arr[i]);
        printf("\n");
    }
    printf("Given array\n");
    for (int i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }

    int count;
    printf("\nUnique elements\n");
    for (int i=0; i<size; i++) {
        count = 0;
        for (int j=0; j<size; j++) {
            if (arr[i] == arr[j]) {
                count++; 
            } 
        } 
        if (count == 1) {
            printf("%d ",arr[i]); 
        }
    }
}
