#include <iostream>
#include <string>
#include <stack>
using namespace std;
string removeDuplicateLetters(string s) {
    int count[256] = {0};
    bool in_stack[256] = {false};
    stack<char> st;
    for(char c : s) count[c]++;
    for(char c : s) {
        count[c]--;
        if(in_stack[c]) continue;
        while(!st.empty() && st.top() > c && count[st.top()] > 0) {
            in_stack[st.top()] = false;
            st.pop();
        }
        st.push(c);
        in_stack[c] = true;
    }
    string res = "";
    while(!st.empty()) { res = st.top() + res; st.pop(); }
    return res;
}
int main() {
    string s; cin >> s;
    cout << removeDuplicateLetters(s) << endl;
    return 0;
}
