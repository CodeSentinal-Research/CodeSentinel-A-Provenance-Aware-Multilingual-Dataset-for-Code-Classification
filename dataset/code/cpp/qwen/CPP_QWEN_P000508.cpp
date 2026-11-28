#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solve(vector<int>& h) {
    int n = h.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] < h[i]) {
            res[st.top()]++;
            st.pop();
        }
        if (!st.empty()) res[st.top()]++;
        st.push(i);
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    vector<int> ans = solve(h);
    for(int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
