#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int solve(string s) {
    stack<int> st;
    st.push(-1);
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(i);
        else {
            st.pop();
            if (st.empty()) st.push(i);
            else res = max(res, i - st.top());
        }
    }
    return res;
}

int main() {
    string s; cin >> s;
    cout << solve(s) << endl;
    return 0;
}
