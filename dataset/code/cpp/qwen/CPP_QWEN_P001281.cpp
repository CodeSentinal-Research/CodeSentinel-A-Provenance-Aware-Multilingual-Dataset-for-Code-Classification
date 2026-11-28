#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string num;
    int k;
    cin >> num >> k;
    
    stack<char> st;
    for (char c : num) {
        while (k > 0 && !st.empty() && st.top() > c) {
            st.pop();
            k--;
        }
        st.push(c);
    }
    
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }
    
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    // Remove leading zeros
    int i = 0;
    while (i < result.length() && result[i] == '0') i++;
    result = result.substr(i);
    
    if (result.empty()) cout << "0" << endl;
    else cout << result << endl;
    
    return 0;
}
