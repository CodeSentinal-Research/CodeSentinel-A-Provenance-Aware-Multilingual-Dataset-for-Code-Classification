#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int calculate(string s) {
    stack<int> stk;
    int sign = 1, res = 0, num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            sign = 1;
            continue;
        }
        if (s[i] == '-') {
            sign = -1;
            continue;
        }
        if (s[i] == '(') {
            stk.push(sign);
            sign = 1;
            continue;
        }
        if (s[i] == ')') {
            int tmp = 0;
            while (!stk.empty() && stk.top() != '(') {
                tmp += stk.top();
                stk.pop();
            }
            stk.pop();
            res += sign * tmp;
            continue;
        }
        if (s[i] == '*') {
            sign = stk.top();
            stk.pop();
            num = sign * (s[i + 1] - '0');
            res += num;
            continue;
        }
        if (s[i] == '/') {
            sign = stk.top();
            stk.pop();
            num = sign * (s[i + 1] - '0');
            res += num;
            continue;
        }
        num = s[i] - '0';
        for (int j = i + 1; j < s.size() && s[j] >= '0' && s[j] <= '9'; j++) {
            num = num * 10 + s[j] - '0';
        }
        res += sign * num;
        i = j;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << calculate(s) << endl;
    return 0;
}