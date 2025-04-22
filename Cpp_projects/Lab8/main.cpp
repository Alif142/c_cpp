#include <iostream>
#include "stacktype.h"
using namespace std;
void isbalanced(string s){
    StackType<char> stk;
    bool balanced = true;
    for (int i=0;i<s.length();i++) {
        if (s[i] == '(') {
                stk.Push('('); 
        } 
        else if(s[i] == ')' && !stk.IsEmpty()) {
           stk.Pop(); 
        }
        else if (s[i] == ')' && stk.IsEmpty()) {
            balanced = false; 
            break;
        }
    }
    if (stk.IsEmpty() && balanced) 
        cout<<"Balacced"<<endl; 

    else
        cout<<"Not Balacced"<<endl; 

}

int main() {
    isbalanced("()");
    isbalanced("(())()(()())()");
    isbalanced("(())()((()");
    isbalanced("(())))((()");
    isbalanced("(())))))))");

    return 0;
}
