Here is a simple implementation of the queue using an array in C++.

#include <iostream>
using namespace std;

class Queue {
private:
    int front;
    int rear;
    int capacity;
    int* queue;
public:
    Queue(int capacity) {
        this->capacity = capacity;
        front = rear = -1;
        queue = new int[capacity];
    }
    ~Queue() {
        delete[] queue;
    }

    bool isFull() {
        return ((rear+1)%capacity == front);
    }

    bool isEmpty() {
        return (front == rear);
    }

    void enqueue(int item) {
        if (isFull(this->capacity)) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear+1)%capacity;
        queue[rear] = item;
        if(front == -1)
            front = rear;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued item: " << queue[front] << endl;
        if(front == rear) {
            front = rear = -1;
        } else {
            front = (front+1)%capacity;
        }
    }

    void front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front item: " << queue[front] << endl;
    }
};

int main() {
    int capacity, q;
    cin >> capacity >> q;
    Queue qObj(capacity);
    for(int i=0; i<q; i++) {
        string op;
        cin >> op;
        if(op == "enqueue") {
            int item;
            cin >> item;
            qObj.enqueue(item);
        } else if(op == "dequeue") {
            qObj.dequeue();
        } else if(op == "front") {
            qObj.front();
        } else if(op == "isEmpty") {
            if(qObj.isEmpty()) {
                cout << "True" << endl;
            } else {
                cout << "False" << endl;
            }
        }
    }
    return 0;
}

This code reads the capacity and number of operations from the input and creates a queue of given capacity. It then processes the operations one by one and prints the results.