#include <iostream>
#include <queue>
#include <string>
using namespace std;

class MyQueue {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }
    int pop() { int x = q1.front(); q1.pop(); return x; }
    int peek() { return q1.front(); }
    bool empty() { return q1.empty(); }
};

int main() {
    int q; cin >> q;
    MyQueue mq;
    while(q--) {
        string op; cin >> op;
        if(op == "push") { int x; cin >> x; mq.push(x); }
        else if(op == "pop") cout << mq.pop() << " ";
        else if(op == "peek") cout << mq.peek() << " ";
        else if(op == "empty") cout << (mq.empty() ? "true" : "false") << " ";
    }
    cout << endl;
    return 0;
}
