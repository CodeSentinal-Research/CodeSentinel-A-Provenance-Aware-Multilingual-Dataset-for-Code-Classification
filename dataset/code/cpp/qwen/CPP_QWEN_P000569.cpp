#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        q.push(x);
    }
    stack<int> st;
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
