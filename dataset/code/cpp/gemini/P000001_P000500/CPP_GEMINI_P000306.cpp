#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int calculate(const std::string& s) {
    std::vector<int> st;
    long long num = 0;
    char sign = '+';
    for (size_t i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
            if (sign == '+') st.push_back(num);
            else if (sign == '-') st.push_back(-num);
            else if (sign == '*') {
                int prev = st.back(); st.pop_back();
                st.push_back(prev * num);
            } else if (sign == '/') {
                int prev = st.back(); st.pop_back();
                st.push_back(prev / num);
            }
            sign = c;
            num = 0;
        }
    }
    return std::accumulate(st.begin(), st.end(), 0);
}

int main() {
    std::string s;
    if (std::getline(std::cin, s)) {
        std::cout << calculate(s) << std::endl;
    }
    return 0;
}