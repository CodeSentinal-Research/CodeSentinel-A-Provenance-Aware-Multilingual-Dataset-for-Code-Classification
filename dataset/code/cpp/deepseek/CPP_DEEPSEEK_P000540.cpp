#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    Queue() {
        front = rear = NULL;
        size = 0;
    }

    void enqueue(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        if(rear == NULL)
            front = rear = temp;
        else {
            rear->next = temp;
            rear = temp;
        }
        size++;
    }

    void dequeue() {
        if(front == NULL)
            cout << "Queue is empty" << endl;
        else {
            Node* temp = front;
            front = front->next;
            delete temp;
            if(front == NULL)
                rear = NULL;
            size--;
        }
    }

    int front() {
        if(front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }

    int size() {
        return size;
    }
};

int main() {
    Queue q;
    int queries, value;
    char operation;
    while(cin >> queries) {
        switch (queries) {
            case 1:
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << q.front() << endl;
                break;
            case 4:
                cout << q.size() << endl;
                break;
            case 5:
                if(q.isEmpty())
                    cout << "Queue is empty" << endl;
                else
                    cout << "Queue is not empty" << endl;
                break;
            default:
                return 0;
        }
    }
    return 0;
}
This code implements a queue using a linked list in C++. It first initializes the front and rear pointers to NULL, and the size of the queue to 0. The enqueue operation adds a new node to the end of the queue. The dequeue operation removes the front node. The front operation returns the data of the front node. The size operation returns the size of the queue. The isEmpty operation checks if the queue is empty.

In the main function, it reads the number of queries, then for each query it reads the operation and the corresponding value. It then performs the operation on the queue and prints the result.