#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <numeric>
long long calculate(std::string s) {
    std::vector<long long> st;
    long long num = 0;
    char sign = '+';
    for (size_t i = 0; i < s.length(); i++) {
        char c = s[i];
        if (std::isdigit(c)) num = num * 10 + (c - '0');
        if ((!std::isdigit(c) && c != ' ') || i == s.length() - 1) {
            if (sign == '+') st.push_back(num);
            else if (sign == '-') st.push_back(-num);
            else if (sign == '*') { long long prev = st.back(); st.pop_back(); st.push_back(prev * num); }
            else if (sign == '/') { long long prev = st.back(); st.pop_back(); st.push_back(prev / num); }
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
        std::cout << calculate(s) << std::endl;
    }
    return 0;
}