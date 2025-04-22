#ifndef STACKTYPE_CPP
#define STACKTYPE_CPP

#include <iostream>
#include "stacktype.h"
template<class T>
StackType<T>::StackType() {
    data = new T[SIZE];
    top = -1;
}

template<class T>
StackType<T>::~StackType() {
    delete[] data;
}

template<class T>
bool StackType<T>::IsEmpty() const {
    return (top == -1);
}

template<class T>
bool StackType<T>::IsFull() const {
    return (top == SIZE - 1);
}

template<class T>
void StackType<T>::Push(T value) {
    if (IsFull()) {
        std::cerr << "Error: Stack is full!" << std::endl;
        return;  // Just return without throwing
    }
    top++;
    data[top] = value;
}

template<class T>
void StackType<T>::Pop() {
    if (IsEmpty()) {
        std::cerr << "Error: Stack is empty!" << std::endl;
        return;  // Just return without throwing
    }
    top--;
}

template<class T>
T StackType<T>::Top() {
    if (IsEmpty()) {
        std::cerr << "Error: Stack is empty!" << std::endl;
        return T();  // Return default-constructed T (e.g., 0 for int)
    }
    return data[top];
}

#endif // STACKTYPE_CPP
