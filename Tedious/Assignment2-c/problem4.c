#include <stdio.h>
void insert(int arr[],int *n,int value){
    (*n)++;
    arr[*n] = value; 
}
int main(){
    int arr[100];
    int n;
    printf("Enter value of n:");
    scanf("%d",&n);
    for (int i=0;i<=n;i++) {
        printf("arr[%d]:",i) ;
        scanf("%d",&arr[i]);
    }
    printf("\nOld array\n");
    for (int i=0;i<=n;i++) {
        printf("%d ",arr[i]);
    }
    
    int value;
    printf("\nEnter a value to insert at the end:\n");
    scanf("%d",&value);

    insert(arr,&n,value);
    printf("\nnew array\n");
    for (int i=0;i<=n;i++) {
        printf("%d ",arr[i]);
    }
}
