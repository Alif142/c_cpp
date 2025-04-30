#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

template <class T>
class UnsortedType {
private:
    struct Node { T data; Node* next; };
    Node* head;
    Node* pointTo;
    int size;
public:
    UnsortedType() : head(nullptr), pointTo(nullptr), size(0) {}
    ~UnsortedType() { MakeEmpty(); }

    int Length() const { return size; }

    void Insert(const T& value) {
        Node* temp = new Node{value, head};
        head = temp;
        ++size;
    }

    void Delete(const T& value) {
        Node* prev = nullptr;
        for (Node* cur = head; cur; cur = cur->next) {
            if (cur->data == value) {
                if (prev) prev->next = cur->next;
                else head = cur->next;
                delete cur;
                --size;
                return;
            }
            prev = cur;
        }
    }

    void Search(const T& value, bool &found) const {
        found = false;
        for (Node* cur = head; cur; cur = cur->next) {
            if (cur->data == value) { found = true; return; }
        }
    }

    void MakeEmpty() {
        while (head) {
            Node* nxt = head->next;
            delete head;
            head = nxt;
        }
        size = 0;
        pointTo = nullptr;
    }

    void Reset() { pointTo = head; }

    void GetNext(T &value) {
        if (!pointTo) return;
        value = pointTo->data;
        pointTo = pointTo->next;
    }
};
#endif // UNSORTEDTYPE_H
