#include <iostream>
#include "QueueType.cpp"
#include "QueueType.h"

using namespace std;

template<class T>
void printQueue(QueueType<T>&que){
    QueueType<T> aux;
    int num;
    while (!que.IsEmpty()) {
        que.Dqueue(num);
        cout<<num<<" ";
        aux.Enqueue(num);
    }

    while (!aux.IsEmpty()) {
        aux.Dqueue(num);
        que.Enqueue(num);
    }
    cout<<endl;
}

void printBinary(int n){
    QueueType<string> que;
    string temp = "1";
    que.Enqueue(temp);
    while (n--) {
        que.Dqueue(temp);
        cout<<temp<<endl;

        string s1,s2;
        s1 = temp + "0";
        que.Enqueue(s1);

        s2 = temp + "1";
        que.Enqueue(s2);
    }
}

int main()
{
    printBinary(10);
    return 0;
}
