#include <iostream>
#include <string>

bool isAutomorphic(long long n) {
    std::string s_n = std::to_string(n);
    std::string s_sq = std::to_string(n * n);
    if (s_sq.length() < s_n.length()) return false;
    return s_sq.substr(s_sq.length() - s_n.length()) == s_n;
}

int main() {
    long long n;
    if (std::cin >> n) {
        std::cout << (isAutomorphic(n) ? "YES" : "NO") << "\n";
    }
    return 0;
}