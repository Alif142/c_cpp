#include <stdio.h>
const int col = 3;
const int row = 3;

int diagonalSum(int arr[row][col]){
    int sum=0;
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            if (i == j) {
                sum += arr[i][j]; 
            }
        }
    }
    return sum;

}

int borderSum(int arr[row][col]){
    int sum = 0;
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            if (i == 0 || i == row-1 || j == 0 || j == col-1) {
                sum += arr[i][j]; 
            }
        }
    }
    return sum;
}

int rowSum(int row_index,int arr[][col]){
    int rowSum = 0;
        for (int j=0;j<col;j++) {
            rowSum+= arr[row_index][j];            
        }
    return rowSum;
}



int colSum(int col_index,int arr[row][col]){
   int colSum = 0; 
    for (int i = 0;i<row;i++) {
        colSum+= arr[i][col_index];
    }
    return colSum;
}

int maxColSum(int arr[row][col]){
    int maxSum = colSum(0,arr);
    for (int i=0;i<col;i++) {
        int currentSum = colSum(i,arr);
        if (currentSum > maxSum) {
            maxSum = currentSum; 
        } 
    }
    return maxSum;
}

int maxRowSum(int arr[][col]){
   int maxSum = rowSum(0, arr); 

    for (int i=1;i<row;i++) {
        int currentSum = rowSum(i,arr); 
        if (currentSum > maxSum) {
            maxSum = currentSum; 
        }
    }
    return maxSum;
}

int main(){
    int arr[row][col];
    printf("Enter array elements:\n");
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            printf("arr[%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);
        } 
    }

    printf("\n");

    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            printf("%d ",arr[i][j]);
        } 
        printf("\n");
    }

    printf("Diagonal sum:%d\n",diagonalSum(arr));
    printf("Border sum:%d\n",borderSum(arr));
    printf("Row0 sum:%d\n",rowSum(0,arr));
    printf("Row1 sum:%d\n",rowSum(1,arr));
    printf("Row2 sum:%d\n",rowSum(2,arr));
    printf("Max row sum:%d\n",maxRowSum(arr));
    printf("Col0 sum:%d\n",colSum(0,arr));
    printf("Col1 sum:%d\n",colSum(1,arr));
    printf("Col2 sum:%d\n",colSum(2,arr));
    printf("Max col sum:%d\n",maxColSum(arr));
}
