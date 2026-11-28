Here is the C++ code that will solve the problem:

#include <iostream>
#include <stack>
using namespace std;

string removeStars(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '*')
            st.push(s[i]);
        else if (!st.empty())
            st.pop();
    }
    string res = "";
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << removeStars(s) << endl;
    return 0;
}
In this code, we use a stack to store the characters of the string. The stack is used to keep track of the non-removed characters. When we encounter a '*', we pop the top element from the stack, which is the non-removed character to the left. This process continues until all '*' have been processed.