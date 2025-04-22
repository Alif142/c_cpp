#include <stdio.h>
void shiftArr1pos(int arr1[] , int arrSize){
    int firstElement = arr1[0];
    for (int i=0;i<arrSize;i++) {
        arr1[i] = arr1[i+1]; 
    }
    arr1[arrSize-1] = firstElement;
}

void arr1Rotate(int arr1[] , int arrSize , int rotFrom){
    for (int i=0;i<rotFrom;i++) {
        shiftArr1pos(arr1,arrSize);
    }
}
int main(){
    int arr1[100];
    int size;
    printf("Enter array size:");
    scanf("%d",&size);
    int n;
    printf("Enter position:");
    scanf("%d",&n);
    printf("Enter array Elements:");

    for (int i=0;i<size;i++) {
        printf("arr1[%d]:",i); 
        scanf("%d",&arr1[i]);
    }

    printf("\nFrom index %d position,array elements are:\n",n);
    for (int i=n;i<size;i++) {
        printf("%d ",arr1[i]); 
    }
    printf("\n Array elements prior to index:\n");
    for (int i=0;i<n;i++) {
        printf("%d ",arr1[i]); 
    }

    arr1Rotate(arr1,size,n);
    printf("\nAfter rotation from index %d,the array is:\n",n);
    for (int i=0;i<size;i++) {
        printf("%d ",arr1[i]); 
    }


}
