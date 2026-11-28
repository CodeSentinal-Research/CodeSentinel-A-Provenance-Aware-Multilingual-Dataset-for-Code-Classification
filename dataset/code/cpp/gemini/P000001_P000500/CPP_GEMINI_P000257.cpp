#include <iostream>
#include <string>
#include <algorithm>
int main() {
    std::string s1, s2;
    if (std::cin >> s1 >> s2) {
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        std::cout << (s1 == s2 ? "Anagram" : "Not Anagram") << std::endl;
    }
    return 0;
}