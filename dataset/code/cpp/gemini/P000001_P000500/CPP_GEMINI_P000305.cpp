#include <iostream>
#include <string>
#include <vector>

int calculate(const std::string& s) {
    std::vector<int> st;
    long long res = 0;
    long long num = 0;
    int sign = 1;
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+' || c == '-') {
            res += sign * num;
            num = 0;
            sign = (c == '+') ? 1 : -1;
        } else if (c == '(') {
            st.push_back(res);
            st.push_back(sign);
            res = 0;
            sign = 1;
        } else if (c == ')') {
            res += sign * num;
            num = 0;
            int prevSign = st.back(); st.pop_back();
            int prevRes = st.back(); st.pop_back();
            res = prevRes + prevSign * res;
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