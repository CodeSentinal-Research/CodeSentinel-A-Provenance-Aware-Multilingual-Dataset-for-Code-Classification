#include <iostream>
#include <string>

bool repeatedSubstringPattern(std::string s) {
    std::string ss = s + s;
    return ss.substr(1, ss.length() - 2).find(s) != std::string::npos;
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::cout << (repeatedSubstringPattern(s) ? "Yes" : "No") << std::endl;
    }
    return 0;
}