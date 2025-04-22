#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1; 
    stack<int> s2;  

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return -1;  
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int front = s2.top();
        s2.pop();
        return front;
    }

    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return -1;  
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }

    int size() {
        return s1.size() + s2.size();
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.front() << endl;  
    cout << "Dequeued element: " << q.dequeue() << endl;  
    
    q.enqueue(4);
    
    cout << "Size: " << q.size() << endl;  
    cout << "Dequeued element: " << q.dequeue() << endl;  
    cout << "Dequeued element: " << q.dequeue() << endl;  
    cout << "Dequeued element: " << q.dequeue() << endl; 
    
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;  

    return 0;
}
