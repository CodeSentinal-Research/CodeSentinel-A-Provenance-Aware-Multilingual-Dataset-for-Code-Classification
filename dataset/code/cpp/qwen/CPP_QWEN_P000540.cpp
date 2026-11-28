#include <iostream>
#include <string>
using namespace std;

struct Node { int val; Node* next; Node(int x) : val(x), next(nullptr) {} };

class Queue {
    Node *front, *rear;
public:
    Queue() { front = rear = nullptr; }
    void enqueue(int x) {
        Node* n = new Node(x);
        if (!rear) { front = rear = n; return; }
        rear->next = n; rear = n;
    }
    int dequeue() {
        if (!front) return -1;
        int x = front->val; Node* t = front; front = front->next;
        if (!front) rear = nullptr; delete t; return x;
    }
    int getFront() { return front ? front->val : -1; }
    bool isEmpty() { return !front; }
};

int main() {
    int q_num; cin >> q_num;
    Queue q;
    while(q_num--) {
        string op; cin >> op;
        if(op == "enqueue") { int x; cin >> x; q.enqueue(x); }
        else if(op == "dequeue") cout << q.dequeue() << " ";
        else if(op == "getFront") cout << q.getFront() << " ";
        else if(op == "isEmpty") cout << (q.isEmpty() ? "true" : "false") << " ";
    }
    cout << endl;
    return 0;
}
