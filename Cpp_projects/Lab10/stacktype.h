#ifndef STACKTYPE_H
#define STACKTYPE_H

class FullStack
{};

class EmptyStack
{};

template <class T>
class StackType
{
    struct Node
    {
        T data;
        Node* next;
    };
private:
    Node* head;
public:
    StackType();
    ~StackType();
    bool IsEmpty();
    bool IsFull();
    void Push(T);
    void Pop();
    void Diagnose(); // Optional
    T Top();
};

#endif // STACKTYPE_H
