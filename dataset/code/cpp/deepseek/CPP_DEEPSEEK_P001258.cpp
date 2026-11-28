#include <iostream>
#include <stack>
using namespace std;

string removeDuplicateLetters(string s) {
    stack<char> st;
    int last[256] = {0}, count[256] = {0};
    int len = s.length();
    
    for(int i = 0; i < len; i++) {
        count[s[i]]++;
    }
    
    for(int i = 0; i < len; i++) {
        if(count[s[i]] > 0) {
            count[s[i]]--;
            if(last[s[i]] == 0) {
                while(!st.empty() && st.top() > s[i] && count[st.top()] > 0) {
                    st.pop();
                }
                st.push(s[i]);
            }
            last[s[i]] = 1;
        }
    }
    
    string res = "";
    while(!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    
    return res;
}

int main() {
    string s;
    cin >> s;
    string res = removeDuplicateLetters(s);
    cout << res << endl;
    return 0;
}