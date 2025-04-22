#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
    BST<int>  bst;
    bst.Insert(11);
    bst.Insert(9);
    bst.Insert(4);
    bst.Insert(2);
    bst.Insert(7);
    bst.Insert(3);
    bst.Insert(17);
    bst.Insert(0);
    bst.Insert(5);
    bst.Insert(1);
    bst.Reset(IN_ORDER);
    int num;
    cout<<"IN_ORDER:";
    for (int i=0;i<bst.Length();i++) {
        bst.GetNext(num,IN_ORDER); 
        cout<<num<<" ";
    }

    bst.Reset(PRE_ORDER);
    cout<<endl<<"PRE_ORDER:";
    for (int i=0;i<bst.Length();i++) {
        bst.GetNext(num,PRE_ORDER); 
        cout<<num<<" ";
    }

    bst.Reset(POST_ORDER);
    cout<<endl<<"POST_ORDER:";
    for (int i=0;i<bst.Length();i++) {
        bst.GetNext(num,POST_ORDER); 
        cout<<num<<" ";
    }

    cout<<endl<<endl;
    bst.BuildOptimalTree();
    bst.Reset(IN_ORDER);
    cout<<"IN_ORDER:";
    for (int i=0;i<bst.Length();i++) {
        bst.GetNext(num,IN_ORDER); 
        cout<<num<<" ";
    }

    bst.Reset(PRE_ORDER);
    cout<<endl<<"PRE_ORDER:";
    for (int i=0;i<bst.Length();i++) {
        bst.GetNext(num,PRE_ORDER); 
        cout<<num<<" ";
    }

    bst.Reset(POST_ORDER);
    cout<<endl<<"POST_ORDER:";
    for (int i=0;i<bst.Length();i++) {
        bst.GetNext(num,POST_ORDER); 
        cout<<num<<" ";
    }
    return 0;
}
