#include <iostream>
#include <string>

int main() {
    std::string s, t;
    if (std::cin >> s >> t) {
        char res = 0;
        for (char c : s) res ^= c;
        for (char c : t) res ^= c;
        std::cout << res << std::endl;
    }
    return 0;
}