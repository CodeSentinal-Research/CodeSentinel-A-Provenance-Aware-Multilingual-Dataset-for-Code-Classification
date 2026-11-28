#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int solve(string s) {
    stack<int> nums, ops;
    long long num = 0; char op = '+';
    for (int i = 0; i <= s.size(); i++) {
        if (i < s.size() && isdigit(s[i])) num = num * 10 + (s[i] - '0');
        else if (i == s.size() || s[i] != ' ') {
            if (op == '+' || op == '-') nums.push(op == '+' ? num : -num);
            else if (op == '*' || op == '/') {
                int top = nums.top(); nums.pop();
                nums.push(op == '*' ? top * num : top / num);
            }
            if (i < s.size()) op = s[i];
            num = 0;
        }
    }
    int res = 0;
    while (!nums.empty()) { res += nums.top(); nums.pop(); }
    return res;
}

int main() {
    string s; getline(cin, s);
    cout << solve(s) << endl;
    return 0;
}
