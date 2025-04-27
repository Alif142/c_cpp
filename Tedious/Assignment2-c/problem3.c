#include <stdio.h>
void insert(int arr[],int *size,int k , int value){
 for (int i = *size;i>k;i--) {
        arr[i] = arr[i-1];
    }
    arr[k] = value;
    (*size)++;
}
int main(){
    int arr[100];
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    printf("\nEnter array elements:");
    for (int i=0;i<size;i++) {
        printf("arr[%d]:",i);
        scanf("%d",&arr[i]); 
        printf("\n");
    }
    printf("\nOld array\n");
    for (int i=0;i<size;i++) {
        printf("%d ",arr[i]); 
    }

    int k;
    printf("Enter index:");
    scanf("%d",&k);
    
    int value;
    printf("Enter value:");
    scanf("%d",&value);

    insert(arr,&size, k, value);

    printf("\nNew array\n");
    for (int i=0;i<size;i++) {
        printf("%d ",arr[i]); 
    }
}

