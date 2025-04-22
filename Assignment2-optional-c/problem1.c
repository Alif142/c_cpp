#include <stdio.h>
void sort(int arr[] , int size){
   for (int i=0; i<size; i++) {
        for (int j = 0;j<size-1-i;j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            } 
        } 
   } 
}
int main(){
    int arr[10] = {4,2,3,1,5,6,8,10,9,7};
    int size = 10;
    sort(arr,size);
    for (int i=0;i<size;i++) {
        printf("%d ",arr[i]); 
    }
}
