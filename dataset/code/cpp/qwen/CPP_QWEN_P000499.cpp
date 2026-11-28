#include <iostream>
#include <string>
#include <stack>
using namespace std;
string makeGood(string s) {
    stack<char> st;
    for(char c : s) {
        if(!st.empty() && abs(st.top() - c) == 32) st.pop();
        else st.push(c);
    }
    string res = "";
    while(!st.empty()) { res = st.top() + res; st.pop(); }
    return res;
}
int main() {
    string s; cin >> s;
    cout << makeGood(s) << endl;
    return 0;
}
