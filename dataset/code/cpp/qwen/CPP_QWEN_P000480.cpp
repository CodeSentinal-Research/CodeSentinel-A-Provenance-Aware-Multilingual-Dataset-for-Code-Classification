#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    string s; cin >> s;
    stack<char> st;
    for(char c : s) {
        if(!st.empty() && st.top() == c) st.pop();
        else st.push(c);
    }
    string res = "";
    while(!st.empty()) { res = st.top() + res; st.pop(); }
    cout << res << endl;
    return 0;
}
