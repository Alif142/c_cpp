#include <stdio.h>
void revStr(char arr[] , int size){
    int start = 0;
    int end = size -1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main(){
    char arr[10] = {'A' , 'L' , 'I' , 'F'}; 
    int size = 4;
    revStr(arr, size);

    for (int i=0;i<size;i++) {
        printf("%c ",arr[i]); 
    }
}
