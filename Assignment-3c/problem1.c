#include <stdio.h>
int max(int *p,int size){
   int max_val = p[0]; 
    for (int i=1;i<size;i++) {
        if (p[i]> max_val) {
           max_val = p[i]; 
        }
    }
    return max_val;
}

int main(){
    int arr[10] = {1,3,4,6,0,2,5};
    int size = 10;
    printf("Max value:%d",max(arr,size));
}
