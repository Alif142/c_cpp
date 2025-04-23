#include <stdio.h>
int getNum(int n){
    return n;
}
int getSquear(int n){
    return n * n;
}
int getCube(int l){
    return l * l * l;
}
float computeSquare(float x){
    return x * x;
}
void  printCube(float x){
    printf("Cube:%.2f\n",(x * x *x));
}
int main(){
    int num;
    printf("Enter num:");
    scanf("%d",&num);
    printf("Square:%d\n",getSquear(num));
    printf("Cube:%d\n",getCube(num));
    printf("Square:%.2f\n",computeSquare((float)num));
    printCube((float)num);
}
