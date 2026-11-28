Here is the C++ code that solves the problem:

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int result = 0;
    stack<char> st;

    for(int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            st.push(str[i]);
        } else {
            if (st.empty()) {
                result++;
            }
            st.pop();
        }
    }

    result += st.size();
    cout << result << "\n";

    return 0;
}
In this code, we use a stack to keep track of the open parentheses. For each closed parenthesis, we pop an open parenthesis from the stack. If the stack is empty (which means we have a closed parenthesis without an open one), we increment the result by 1. In the end, the size of the stack (i.e., the number of unmatched open parentheses) is the minimum number of insertions required.