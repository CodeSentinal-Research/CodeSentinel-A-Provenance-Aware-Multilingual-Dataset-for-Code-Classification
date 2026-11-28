#include <iostream>
#include <stack>
#include <string>
using namespace std;
class MinStack {
    stack<int> st, min_st;
public:
    void push(int val) {
        st.push(val);
        if(min_st.empty() || val <= min_st.top()) min_st.push(val);
    }
    void pop() {
        if(st.top() == min_st.top()) min_st.pop();
        st.pop();
    }
    int top() { return st.top(); }
    int getMin() { return min_st.top(); }
};
int main() {
    int q; cin >> q;
    MinStack ms;
    while(q--) {
        string op; cin >> op;
        if(op == "push") { int x; cin >> x; ms.push(x); }
        else if(op == "pop") { ms.pop(); }
        else if(op == "top") { cout << ms.top() << endl; }
        else if(op == "getMin") { cout << ms.getMin() << endl; }
    }
    return 0;
}
