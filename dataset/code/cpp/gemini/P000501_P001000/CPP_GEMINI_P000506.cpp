#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <numeric>
long long parse(const std::string& s, int& i) {
    std::vector<long long> st;
    long long num = 0;
    char sign = '+';
    while (i < (int)s.length()) {
        char c = s[i++];
        if (std::isdigit(c)) num = num * 10 + (c - '0');
        if (c == '(') num = parse(s, i);
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == ')' || i == (int)s.length()) {
            if (sign == '+') st.push_back(num);
            else if (sign == '-') st.push_back(-num);
            else if (sign == '*') { long long p = st.back(); st.pop_back(); st.push_back(p * num); }
            else if (sign == '/') { long long p = st.back(); st.pop_back(); st.push_back(p / num); }
            if (c == ')') break;
            sign = c;
            num = 0;
        }
    }
    long long sum = 0;
    for (long long v : st) sum += v;
    return sum;
}
int main() {
    std::string s;
    if (std::getline(std::cin, s)) {
        int i = 0;
        std::cout << parse(s, i) << std::endl;
    }
    return 0;
}