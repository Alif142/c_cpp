#include <stdio.h>
void squareArray(int arr[] , int size){
   for (int i=0;i<size ; i++) {
        arr[i] = arr[i] * arr[i]; 
   } 
}
void revArray(int arr[], int size){
    int temp;
    int start = 0;
    int end = size - 1;

    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

}
int main(){
   int arr [10] = {1,3,5,7,9}; 
    int size = 5;
    squareArray(arr,size);
    revArray(arr, size);
    for (int i=0;i<size;i++) {
        printf("%d ",arr[i]); 
    }
}
