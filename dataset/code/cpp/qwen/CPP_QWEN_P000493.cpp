#include <iostream>
#include <string>
#include <stack>
using namespace std;
string removeKdigits(string num, int k) {
    stack<char> st;
    for(char c : num) {
        while(!st.empty() && k > 0 && st.top() > c) { st.pop(); k--; }
        st.push(c);
    }
    while(k > 0 && !st.empty()) { st.pop(); k--; }
    string res = "";
    while(!st.empty()) { res = st.top() + res; st.pop(); }
    int start = 0;
    while(start < res.size() && res[start] == '0') start++;
    return res.substr(start).empty() ? "0" : res.substr(start);
}
int main() {
    string num; int k; cin >> num >> k;
    cout << removeKdigits(num, k) << endl;
    return 0;
}
