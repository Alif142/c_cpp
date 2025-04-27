#include <stdio.h>
void modify(int arr[],int value, int size , int replace){
    for (int i=0;i<size;i++) {
        if (arr[i] == value) {
            arr[i] = replace; 
        } 
    }
}
int main(){
    int arr[100];
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    printf("\nEnter array elements:\n");
    for (int i=0;i<size;i++) {
        printf("arr[%d]:",i);
        scanf("%d",&arr[i]); 
        printf("\n");
    }

    printf("\nOld array\n");
    for (int i=0;i<size;i++) {
        printf("%d ",arr[i]); 
    }

    int value,replace;
    printf("\nEnter value you want to replace:");
    scanf("%d",&value);
    printf("\nEnter new value:");
    scanf("%d",&replace);
    modify(arr,value,size,replace);
    printf("\nNew array\n");
    for (int i=0;i<size;i++) {
        printf("%d ",arr[i]); 
    }

}
