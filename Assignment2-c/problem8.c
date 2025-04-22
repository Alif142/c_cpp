#include <stdio.h>
void RevArr ( int arr[], int size){
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }


}
int main(){
    int arr[100];
    int size;

    printf("Enter size:");
    scanf("%d",&size);

    printf("Input elements\n");
    for (int i=0;i< size ; i++) {
        printf("arr[%d]:",i);
        scanf("%d",&arr[i]);
    }

    printf("\nGiven array\n");
    for (int i=0;i< size ; i++) {
        printf("%d ",arr[i]);
    }

    RevArr(arr,size);

    printf("\nNew array\n");
    for (int i=0;i< size ; i++) {
        printf("%d ",arr[i]);
    }

}
