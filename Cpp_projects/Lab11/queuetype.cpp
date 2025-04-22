#include "queuetype.h"
#include <iostream>
using namespace std;

template <class T>
QueueType<T>::QueueType()
{
    front = NULL;
    rear = NULL;
}

template <class T>
bool QueueType<T>::IsEmpty()
{
    return (front == NULL);
}

template<class T>
bool QueueType<T>::IsFull()
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
void QueueType<T>::Enqueue(T value)
{
    if (IsFull())
        throw FullQueue();
    else
    {
        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;

        if (rear == NULL)
            front = temp;
        else
            rear->next = temp;
        rear = temp;
    }
}

template <class T>
void QueueType<T>::Dequeue(T &value)
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        Node* temp = front;
        value = front->data;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }
}

template <class T>
void QueueType<T>::MakeEmpty()
{
    Node* temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
}

template <class T>
QueueType<T>::~QueueType()
{
    MakeEmpty();
}
