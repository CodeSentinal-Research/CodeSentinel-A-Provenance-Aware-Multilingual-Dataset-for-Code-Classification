#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int solve(string s) {
    long long num = 0, last = 0, res = 0;
    char op = '+';
    for (int i = 0; i <= s.length(); i++) {
        char c = (i < s.length()) ? s[i] : '+';
        if (isdigit(c)) num = num * 10 + (c - '0');
        if (!isdigit(c) && c != ' ') {
            if (op == '+' || op == '-') { res += last; last = (op == '+') ? num : -num; }
            else if (op == '*') last *= num;
            else if (op == '/') last /= num;
            op = c; num = 0;
        }
    }
    return res + last;
}

int main() {
    string s; getline(cin, s);
    cout << solve(s) << endl;
    return 0;
}
