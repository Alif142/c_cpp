#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

static const int SIZE = 100;

template<class T>
class SortedType
{
public:
    SortedType();
    ~SortedType();
    int Length();
    bool IsFull();
    void MakeEmpty();
    void Insert(T value);
    void Search(T value, bool& found);
    void Delete(T value);
    void GetNext(T& value);
    void Reset();

private:
    T* data;
    int currentSize;
    int pointTo;
};

#endif // SORTEDTYPE_H
