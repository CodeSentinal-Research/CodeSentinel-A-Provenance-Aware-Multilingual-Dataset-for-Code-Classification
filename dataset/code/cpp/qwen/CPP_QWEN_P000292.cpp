#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    stack<string> st;
    string res = "";
    for(int i=0;i<s.size();i++) {
        if(isdigit(s[i])) { int num=0; while(i<s.size()&&isdigit(s[i])) num=num*10+(s[i++]-'0'); i--; st.push(to_string(num)); }
        else if(s[i]=='[') st.push("[");
        else if(s[i]==']') {
            string str = "";
            while(st.top()!="[") { str = st.top()+str; st.pop(); }
            st.pop();
            int num = stoi(st.top()); st.pop();
            string t = "";
            for(int j=0;j<num;j++) t+=str;
            st.push(t);
        } else st.push(string(1, s[i]));
    }
    string res2 = "";
    while(!st.empty()) { res2 = st.top()+res2; st.pop(); }
    cout << res2 << endl;
    return 0;
}
