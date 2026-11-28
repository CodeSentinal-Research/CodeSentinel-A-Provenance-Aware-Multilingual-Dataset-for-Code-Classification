#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

bool solve(vector<int>& input, vector<int>& output) {
    stack<int> st; queue<int> q;
    for (int x : input) q.push(x);
    int out_idx = 0;
    while (!q.empty() || !st.empty()) {
        if (!st.empty() && st.top() == output[out_idx]) { st.pop(); out_idx++; }
        else if (!q.empty()) { st.push(q.front()); q.pop(); }
        else return false;
    }
    return out_idx == output.size();
}

int main() {
    int n; cin >> n;
    vector<int> in(n), out(n);
    for(int i = 0; i < n; i++) cin >> in[i];
    for(int i = 0; i < n; i++) cin >> out[i];
    cout << (solve(in, out) ? "true" : "false") << endl;
    return 0;
}
