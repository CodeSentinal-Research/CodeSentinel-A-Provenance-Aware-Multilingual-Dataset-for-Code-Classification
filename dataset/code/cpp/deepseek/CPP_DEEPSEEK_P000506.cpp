#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

int calculate(string s) {
    stack<int> stk;
    int sign = 1, res = 0, tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            res += tmp * sign;
            tmp = 0, sign = 1;
        } else if (s[i] == '-') {
            res += tmp * sign;
            tmp = 0, sign = -1;
        } else if (s[i] == '(') {
            stk.push(res);
            stk.push(sign);
            sign = 1, res = 0;
        } else if (s[i] == ')') {
            res += tmp * sign;
            tmp = 0, sign = stk.top(); stk.pop();
            res *= sign, sign = stk.top(); stk.pop();
        } else if (s[i] == '*') {
            tmp *= sign;
        } else if (s[i] == '/') {
            tmp /= sign;
        }
    }
    res += tmp;
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << calculate(s) << endl;
    return 0;
}
This C++ program uses a stack to keep track of the sign and result. It iterates through the input string and performs the appropriate operations based on the characters in the string. The final result is the sum of the current result and the sign multiplied by the next number in the string (or the current sign if there is no next number). The parentheses allow for nesting of operations, and the program handles the sign of the parentheses by pushing the sign onto the stack when it encounters a '(', and popping the sign when it encounters a ')'.