#include <stdio.h>
void delete(int arr[],int value,int *size){
  for (int i=0;i<*size;i++) {
        if (value == arr[i]) {
            for (int j=i;j<*size;j++) {
                arr[j] = arr[j+1]; 
            } 
            break;
        }
    }
    (*size)--;
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
    int value;

    printf("\nEnter value:");
    scanf("%d",&value);
    delete(arr,value,&size);
    printf("\nNew array\n");
    for (int i=0;i<size;i++) {
        printf("%d ",arr[i]); 
    }

}
