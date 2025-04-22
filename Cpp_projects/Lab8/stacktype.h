#ifndef STACKTYPE_H
#define STACKTYPE_H

const int SIZE = 5;

// Exception classes
class FullStack {};
class EmptyStack {};

template<class T>
class StackType {
private:
    T* data;
    int top;
public:
    StackType();
    ~StackType();
    bool IsFull() const;
    bool IsEmpty() const;
    void Push(T);
    void Pop();
    T Top();
};

#include "stacktype.cpp"  // Include implementation
#endif // STACKTYPE_H
