#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int solve(string s) {
    stack<int> st;
    st.push(0);
    for (char c : s) {
        if (c == '(') {
            st.push(0);
        } else {
            int v = st.top(); st.pop();
            int w = st.top(); st.pop();
            st.push(w + max(2 * v, 1));
        }
    }
    return st.top();
}

int main() {
    string s; cin >> s;
    cout << solve(s) << endl;
    return 0;
}
