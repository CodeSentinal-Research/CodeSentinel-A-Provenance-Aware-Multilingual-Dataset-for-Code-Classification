#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solve(vector<int>& p) {
    stack<int> st;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && p[st.top()] >= p[i]) {
            p[st.top()] -= p[i];
            st.pop();
        }
        st.push(i);
    }
    return p;
}

int main() {
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    vector<int> ans = solve(p);
    for(int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
