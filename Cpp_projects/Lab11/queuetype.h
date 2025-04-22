#ifndef QUEUETYPE_H
#define QUEUETYPE_H

class FullQueue
{};

class EmptyQueue
{};

template <class T>
class QueueType
{
    struct Node
    {
        T data;
        Node* next;
    };
private:
    Node *front;
    Node *rear;
public:
    QueueType();
    ~QueueType();
    bool IsEmpty();
    bool IsFull();
    void MakeEmpty();
    void Enqueue(T);
    void Dequeue(T &value);
};
#endif // QUEUETYPE_H
