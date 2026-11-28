#include <iostream>
#include <string>

bool isDuckNumber(const std::string& s) {
    if (s.empty() || s[0] == '0') return false;
    return s.find('0') != std::string::npos;
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::cout << (isDuckNumber(s) ? "YES" : "NO") << "\n";
    }
    return 0;
}