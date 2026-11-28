#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool solve(string expr) {
    stack<bool> st;
    for (char c : expr) {
        if (c == 't') st.push(true);
        else if (c == 'f') st.push(false);
        else if (c == ')') {
            bool val = st.top(); st.pop();
            char op = st.top(); st.pop(); st.pop();
            if (op == '!') val = !val;
            st.push(val);
        } else if (c != ',' && c != '(') {
            st.push(c == 't');
        }
    }
    return st.top();
}

int main() {
    string s; cin >> s;
    cout << (solve(s) ? "true" : "false") << endl;
    return 0;
}
