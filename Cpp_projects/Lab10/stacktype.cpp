#include <iostream>
#include "stacktype.h"
using namespace std;

template <class T>
StackType<T>::StackType()
{
    head = NULL;
}

template <class T>
bool StackType<T>::IsEmpty()
{
    return (head == NULL);
}

template <class T>
bool StackType<T>::IsFull()
{
    try
    {
        Node* temp = new Node;
        delete temp;
        return false;
    }
    catch (bad_alloc &exception)
    {
        return true;
    }
}

template <class T>
void StackType<T>::Push(T value)
{
    if (IsFull())
        throw FullStack();
    else
    {

        Node* temp = new Node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }
}

template <class T>
void StackType<T>::Pop()
{
    if (IsEmpty())
        throw EmptyStack();
    else
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
T StackType<T>::Top()
{
    if (IsEmpty())
        throw EmptyStack();
    else
        return head->data;
}

template <class T>
StackType<T>::~StackType()
{
    Node* i = head;
    Node* nextNode;

    while (i != NULL)
    {
        nextNode = i->next; // Store the next node
        delete i;           // Delete the current node
        i = nextNode;       // Move to the next node
    }
}

// Optional
template <class T>
void StackType<T>::Diagnose()
{
    Node* i = head;

    while (i != NULL)
    {
        cout << "self: " << i << ", data: " << i->data << ", next: " << i->next << endl;
        i = i->next;
    }
}
