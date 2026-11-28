Here is the code:

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s) {
    int maxLength = 0;
    stack<int> indexes;
    indexes.push(-1);  

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            indexes.push(i);
        } else {
            indexes.pop();
            if(indexes.empty()) {
                indexes.push(i);
            } else {
                maxLength = max(maxLength, i - indexes.top());
            }
        }
    }

    return maxLength;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "The length of the longest valid parentheses is: " << longestValidParentheses(s) << endl;
    return 0;
}
This code implements the concept of a stack to solve the problem. The stack is used to track the indices of the parentheses. When a '(', its index is pushed into the stack. When a ')', the top element of the stack is popped. If the stack is empty, a '(' is found at the end of the string, so a sentinel value is pushed into the stack (which is -1 in this case). The maximum length found is updated at each step.