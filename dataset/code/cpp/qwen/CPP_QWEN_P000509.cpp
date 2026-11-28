#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

string solve(string s) {
    stack<char> st;
    for (char c : s) {
        if (isdigit(c)) {
            if (!st.empty()) st.pop();
        } else {
            st.push(c);
        }
    }
    string res = "";
    while (!st.empty()) { res = st.top() + res; st.pop(); }
    return res;
}

int main() {
    string s; cin >> s;
    cout << solve(s) << endl;
    return 0;
}
