#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseSubstring(string s) {
    stack<char> stk;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            stk.push(s[i]);
        else if (s[i] == ')') {
            string temp = "";
            while (!stk.empty() && stk.top() != '(') {
                temp = stk.top() + temp;
                stk.pop();
            }
            if (!stk.empty()) stk.pop(); 
            for (char c : temp) stk.push(c);
        }
        else if (!stk.empty()) {
            char c = stk.top();
            stk.pop();
            s[i] = c;
        }
    }
    return s;
}

int main() {
    string s;
    cin >> s;
    cout << reverseSubstring(s);
    return 0;
}
This code uses a stack to handle the input string. It iterates over the string, pushing each character onto the stack. If it encounters a closing parenthesis ')', it pops all characters until it encounters the matching opening parenthesis '('. It then stores all popped characters in a string. This string is then reversed and pushed back onto the stack. If it encounters any other characters, it just replaces the top character of the stack with the current character. Finally, it prints the resulting string.