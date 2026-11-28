Here's the code to solve the problem:

#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int calculate(string s) {
    stack<int> stk;
    int sign = 1, res = 0, curr = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') continue;

        if(isdigit(s[i])) {
            curr = 0;
            while(i < s.size() && isdigit(s[i])) {
                curr = (curr * 10) + (s[i] - '0');
                i++;
            }
            i--;
            res += sign * curr;
            sign = 1;
        } else if(s[i] == '-') {
            sign = -1;
        } else if(s[i] == '(') {
            stk.push(res);
            stk.push(sign);
            res = 0;
            sign = 1;
        } else if(s[i] == ')') {
            res = 0;
            int tempSign = stk.top();
            stk.pop();
            res += tempSign;
            res *= sign;
            sign = stk.top();
            stk.pop();
        }
    }

    return res;
}

int main() {
    string s;
    cin >> s;
    cout << calculate(s) << endl;
    return 0;
}
This code uses a stack to handle the parentheses and the sign of each operation. The stack stores the sign and result of the operation so far. When a '(' is encountered, the result and sign are pushed onto the stack. When a ')' is encountered, the sign is popped from the stack and the result is updated. The sign is updated when a '*' or '/' is encountered.