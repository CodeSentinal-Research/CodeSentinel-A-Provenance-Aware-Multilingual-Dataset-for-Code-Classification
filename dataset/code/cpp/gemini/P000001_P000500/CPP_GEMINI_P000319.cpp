#include <iostream>
#include <string>
#include <cmath>

bool isOneEditDistance(std::string s, std::string t) {
    if (s == t) return false;
    int m = s.length(), n = t.length();
    if (std::abs(m - n) > 1) return false;
    for (int i = 0; i < std::min(m, n); i++) {
        if (s[i] != t[i]) {
            if (m == n) return s.substr(i + 1) == t.substr(i + 1);
            else if (m < n) return s.substr(i) == t.substr(i + 1);
            else return s.substr(i + 1) == t.substr(i);
        }
    }
    return std::abs(m - n) == 1;
}

int main() {
    std::string s, t;
    if (std::cin >> s >> t) {
        std::cout << (isOneEditDistance(s, t) ? "Yes" : "No") << std::endl;
    }
    return 0;
}