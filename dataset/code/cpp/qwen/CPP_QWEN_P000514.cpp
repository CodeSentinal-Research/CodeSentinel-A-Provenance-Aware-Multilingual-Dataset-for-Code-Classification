#include <iostream>
#include <string>
#include <stack>
using namespace std;

char solve(string s) {
    stack<char> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '?') {
            char a = st.top(); st.pop();
            char b = st.top(); st.pop();
            st.push(s[i-1] == 'T' ? a : b);
            i--;
        } else if (s[i] != ':') {
            st.push(s[i]);
        }
    }
    return st.top();
}

int main() {
    string s; cin >> s;
    cout << solve(s) << endl;
    return 0;
}
