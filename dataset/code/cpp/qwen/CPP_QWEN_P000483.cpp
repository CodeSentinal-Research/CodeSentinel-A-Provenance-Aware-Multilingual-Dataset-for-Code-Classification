#include <iostream>
#include <queue>
#include <string>
using namespace std;
class MyStack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }
    int pop() {
        int val = q1.front(); q1.pop();
        return val;
    }
    int top() { return q1.front(); }
    bool empty() { return q1.empty(); }
};
int main() {
    int q; cin >> q;
    MyStack st;
    while(q--) {
        string op; cin >> op;
        if(op == "push") { int x; cin >> x; st.push(x); }
        else if(op == "pop") { cout << st.pop() << endl; }
        else if(op == "top") { cout << st.top() << endl; }
        else if(op == "empty") { cout << (st.empty() ? "true" : "false") << endl; }
    }
    return 0;
}
