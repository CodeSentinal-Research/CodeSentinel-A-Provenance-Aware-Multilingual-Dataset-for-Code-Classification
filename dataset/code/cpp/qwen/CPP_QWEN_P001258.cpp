#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<int> lastPos(26, -1);
    for (int i = 0; i < s.length(); ++i) {
        lastPos[s[i]-'a'] = i;
    }
    
    stack<char> st;
    vector<bool> inStack(26, false);
    vector<bool> visited(26, false);
    
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (visited[c-'a']) continue;
        
        while (!st.empty() && st.top() > c && lastPos[st.top()-'a'] > i) {
            inStack[st.top()-'a'] = false;
            st.pop();
        }
        
        st.push(c);
        inStack[c-'a'] = true;
        visited[c-'a'] = true;
    }
    
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    cout << result << endl;
    return 0;
}
