#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CircularQueue {
    vector<int> q; int front_idx, rear_idx, size, cap;
public:
    CircularQueue(int k) { q.resize(k); front_idx = rear_idx = size = 0; cap = k; }
    bool enQueue(int x) { if (size == cap) return false; q[rear_idx] = x; rear_idx = (rear_idx + 1) % cap; size++; return true; }
    bool deQueue() { if (size == 0) return false; front_idx = (front_idx + 1) % cap; size--; return true; }
    int Front() { return size == 0 ? -1 : q[front_idx]; }
    int Rear() { return size == 0 ? -1 : q[(rear_idx - 1 + cap) % cap]; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == cap; }
};

int main() {
    int cap, q_num; cin >> cap >> q_num;
    CircularQueue cq(cap);
    while(q_num--) {
        string op; cin >> op;
        if(op == "enQueue") { int x; cin >> x; cout << (cq.enQueue(x) ? "true" : "false") << " "; }
        else if(op == "deQueue") cout << (cq.deQueue() ? "true" : "false") << " ";
        else if(op == "Front") cout << cq.Front() << " ";
        else if(op == "Rear") cout << cq.Rear() << " ";
    }
    cout << endl;
    return 0;
}
