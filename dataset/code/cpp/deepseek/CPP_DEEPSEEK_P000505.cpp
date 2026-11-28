#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int calculate(string s) {
    stack<int> stk;
    int res = 0, sign = 1, n = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        if (s[i] == '+' || s[i] == '-') {
            res += sign * n;
            n = 0;
            sign = s[i] == '+' ? 1 : -1;
        } else if (s[i] == '*' || s[i] == '/') {
            if (s[i] == '*') {
                n *= stk.top();
                stk.pop();
                stk.push(n);
            } else {
                n = stk.top() / n;
                stk.pop();
                stk.push(n);
           
            }
           
        } else {
            while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                n = n * 10 + s[i] - '0';
                i++;
            }
            i--;
            stk.push(n);
            n = 0;
        }
    }
    res += sign * n;
    while (!stk.empty()) {
        res -= stk.top();
        stk.pop();
    }
    return res;
}

int main() {
    cout << calculate("1 + 2 * 3");
    return 0;
}

This C++ program implements a calculator that evaluates an arithmetic expression. The program uses a stack to store the integers to be operated on, and the current result and the current sign of the current integer. 

The expression is read character by character and the current character is processed accordingly. If the current character is a space, then the current result and the sign of the current integer are pushed to the stack.

If the current character is a sign (either '+' or '-'), then the current result and the sign of the current integer are pushed to the stack. 

If the current character is a multiplication ('*') or division ('/'), then the current result and the sign of the current integer are popped from the stack and the current result is updated with these values. 

Finally, if the current character is a digit, then the current integer is updated with this digit and the current result is pushed to the stack.

The final result is the sum of the current result and all integers stored in the stack.