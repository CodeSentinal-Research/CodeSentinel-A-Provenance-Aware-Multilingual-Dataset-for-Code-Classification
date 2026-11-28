#include <iostream>
#include <string>
#include <vector>

bool sameCharacters(std::string s1, std::string s2) {
    if (s1.length() != s2.length()) return false;
    std::vector<int> count(256, 0);
    for (char c : s1) count[(unsigned char)c]++;
    for (char c : s2) {
        if (--count[(unsigned char)c] < 0) return false;
    }
    return true;
}

int main() {
    std::string s1, s2;
    if (std::cin >> s1 >> s2) {
        std::cout << (sameCharacters(s1, s2) ? "Yes" : "No") << std::endl;
    }
    return 0;
}