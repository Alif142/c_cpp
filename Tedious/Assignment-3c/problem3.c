#include <stdio.h>
void rev_arr(int *arr1, int *rev_arr1, int size){
    int j=0;
    for (int i=size-1; i>=0; i--) {
        rev_arr1[j] = arr1[i];  
        j++;
    }
}

int  main()
{
    int arr[5] = {1,2,3,4,5};
    int revArr[5];
    int size = 5;
    rev_arr(arr,revArr,size);
    for (int i=0;i<size;i++) {
        printf("%d ",revArr[i]); 
    }
    return 0;
}
