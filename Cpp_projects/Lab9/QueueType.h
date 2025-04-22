#ifndef QUEUETYPE_H
#define QUEUETYPE_H
const int SIZE = 100;
class FullQueue{};
class EmptyQueue{};

template<class T>

class QueueType
{
private:
    T *data;
    int front;
    int rear;
    int size;

public:
    QueueType();
    QueueType(int s);
    ~QueueType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Enqueue(T value);
    void Dqueue(T &value);
};

#endif // QUEUETYPE_H
