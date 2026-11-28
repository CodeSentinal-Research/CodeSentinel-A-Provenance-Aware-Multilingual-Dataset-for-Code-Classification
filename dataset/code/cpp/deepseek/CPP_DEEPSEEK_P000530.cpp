#include <iostream>
using namespace std;

class CircularQueue {
    private:
        int front, rear, capacity;
        int* queue;
    public:
        CircularQueue(int capacity) {
            this->capacity = capacity;
            front = rear = -1;
            queue = new int[capacity];
        }
        
        ~CircularQueue() {
            delete[] queue;
        }
        
        bool isFull() {
            if((rear + 1) % capacity == front) {
                return true;
            }
            return false;
        }
        
        bool isEmpty() {
            if(rear == -1) {
                return true;
            }
            return false;
        }
        
        void enQueue(int data) {
            if(isFull()) {
                cout << "Queue is full\n";
                return;
            }
            if(isEmpty()) {
                front = 0;
            }
            rear = (rear + 1) % capacity;
            queue[rear] = data;
            cout << "Enqueued " << data << "\n";
        }
        
        void deQueue() {
            if(isEmpty()) {
                cout << "Queue is empty\n";
                return;
            }
            cout << "Dequeued " << queue[front] << "\n";
            if(front == rear) {
                isEmpty();
            } else {
                front = (front + 1) % capacity;
            }
        }
        
        void Front() {
            if(isEmpty()) {
                cout << "Queue is empty\n";
                return;
            }
            cout << "Front element is " << queue[front] << "\n";
        }
        
        void Rear() {
            if(isEmpty()) {
                cout << "Queue is empty\n";
                return;
            }
            cout << "Rear element is " << queue[rear] << "\n";
        }
};

void processQueries(int capacity, int q, int queries[]) {
    CircularQueue cq(capacity);
    for(int i=0; i<q; i++) {
        switch(queries[i]) {
            case 1:
                cin >> capacity;
                cq = CircularQueue(capacity);
                break;
            case 2:
                cin >> capacity;
                cq = CircularQueue(capacity);
                break;
            case 3:
                cin >> capacity;
                cq = CircularQueue(capacity);
                break;
            case 4:
                cq.enQueue(capacity);
                break;
            case 5:
                cq.deQueue();
                break;
            case 6:
                cq.Front();
                break;
            case 7:
                cq.Rear();
                break;
            case 8:
                cout << (cq.isEmpty() ? "true" : "false") << "\n";
                break;
            case 9:
                cout << (cq.isFull() ? "true" : "false") << "\n";
                break;
            default:
                break;
        }
    }
}

int main() {
    int capacity, q, queries[10000];
    cin >> capacity >> q;
    for(int i=0; i<q; i++) {
        cin >> queries[i];
    }
    processQueries(capacity, q, queries);
    return 0;
}