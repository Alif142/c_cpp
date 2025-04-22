#include <stdio.h>
int main(){
    char arr[20] = "Bangladesh";
    char voyel [] = "AEIOUaeiou";
    int sizeV = 10;
    int sizeArr = 10;
    int voyelCount = 0;
    int consonentCount = 0;
    for (int i=0;i<sizeArr;i++) {
        int isVoyel = 0;
        for (int j=0;j<sizeV;j++) {
            if (arr[i] == voyel[j]) {
                isVoyel = 1;
                break;
            } 
        } 
        if (isVoyel) {
            voyelCount++; 
        }
        else {
            if ((arr[i] >='A' && arr[i] <= 'Z')|| (arr[i] >='a' && arr[i] <= 'z')) {
                consonentCount++; 
            }
        }
    }
    printf("Voyels:%d\n",voyelCount);
    printf("Consonent:%d",consonentCount);
    return 0;
}
