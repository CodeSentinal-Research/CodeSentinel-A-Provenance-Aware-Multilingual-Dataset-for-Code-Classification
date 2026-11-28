#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Queue {
    vector<int> q; int front_idx, rear_idx, size;
public:
    Queue(int cap) { q.resize(cap); front_idx = rear_idx = size = 0; }
    void enqueue(int x) { if (size < q.size()) { q[rear_idx] = x; rear_idx = (rear_idx + 1) % q.size(); size++; } }
    int dequeue() { if (size == 0) return -1; int x = q[front_idx]; front_idx = (front_idx + 1) % q.size(); size--; return x; }
    int front() { return size == 0 ? -1 : q[front_idx]; }
    bool isEmpty() { return size == 0; }
};

int main() {
    int cap, q_num; cin >> cap >> q_num;
    Queue q(cap);
    while(q_num--) {
        string op; cin >> op;
        if(op == "enqueue") { int x; cin >> x; q.enqueue(x); }
        else if(op == "dequeue") cout << q.dequeue() << " ";
        else if(op == "front") cout << q.front() << " ";
        else if(op == "isEmpty") cout << (q.isEmpty() ? "true" : "false") << " ";
    }
    cout << endl;
    return 0;
}
