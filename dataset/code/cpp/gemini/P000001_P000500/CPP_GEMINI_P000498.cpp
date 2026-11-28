#include <iostream>
#include <string>
#include <stack>
#include <cctype>
long long calculate(const std::string& s) {
    std::stack<long long> st;
    long long res = 0, num = 0, sign = 1;
    for (char c : s) {
        if (std::isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+' || c == '-') {
            res += sign * num;
            num = 0;
            sign = (c == '+') ? 1 : -1;
        } else if (c == '(') {
            st.push(res);
            st.push(sign);
            res = 0;
            sign = 1;
        } else if (c == ')') {
            res += sign * num;
            num = 0;
            res *= st.top(); st.pop();
            res += st.top(); st.pop();
        }
    }
    res += sign * num;
    return res;
}
int main() {
    std::string s;
    if (std::getline(std::cin, s)) {
        std::cout << calculate(s) << std::endl;
    }
    return 0;
}