#include <iostream>
using namespace std;

int main () {
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int a[n];
    int i = 0;
    for (int x : a) {
        cin>>a[i];
        i++;
    }
    for (int x:a) {
       cout<<x<<" "; 
    }
    return 0;
}
