#include <iostream>
#include <string>

int main() {
    std::string s;
    if (std::cin >> s) {
        long long cur = 0;
        for (size_t i = 0; i < s.length(); i++) {
            cur += s[i] - 'a' + 1;
            std::cout << cur << (i + 1 == s.length() ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}