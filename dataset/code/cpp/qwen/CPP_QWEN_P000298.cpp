#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    int ans=0, l=-1;
    stack<int> st; st.push(-1);
    for(int i=0;i<s.size();i++) {
        if(s[i]=='(') st.push(i);
        else { st.pop(); if(st.empty()) st.push(i); else ans=max(ans,i-st.top()); }
    }
    cout << ans << endl;
    return 0;
}
