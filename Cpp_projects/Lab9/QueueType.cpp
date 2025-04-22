#include "QueueType.h"
#include <iostream>
using namespace std;

template<class T>
QueueType<T>::QueueType(){
    data = new T[SIZE];
    front = rear = 0;
}

template<class T>
QueueType<T>::QueueType(int s){
    size = s + 1;
    data = new T[SIZE];
    front = rear = 0;
}

template<class T>
QueueType<T>::~QueueType(){
    delete [] data;
}

template<class T>
void QueueType<T>::MakeEmpty(){
    front = rear = 0;
}

template<class T>
bool QueueType<T>::IsFull(){
    return ((rear + 1) % size == front);
}

template<class T>
bool QueueType<T>::IsEmpty(){
    return (front == rear);
}
template<class T>
void QueueType<T>::Enqueue(T value){
    try {
        if (IsFull()) {
            throw FullQueue(); 
        }

        else {
            rear = (rear + 1)% size;
            data[rear] = value;
        }
    }

    catch (FullQueue e) {
        cout<<"Queue over flow"<<endl; 
    }
}

template<class T>
void QueueType<T>::Dqueue(T &value){
    try {
        if (IsEmpty()) {
            throw EmptyQueue(); 
        }
        else {
            front = (front + 1) % size;
            value = data[front];
        }
    }

    catch (EmptyQueue e) {
        cout<<"Queue under flow"<<endl; 
    }
}
