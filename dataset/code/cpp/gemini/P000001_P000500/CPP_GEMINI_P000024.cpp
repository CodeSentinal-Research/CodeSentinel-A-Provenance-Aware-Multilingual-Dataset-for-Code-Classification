#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string s;
    if (std::cin >> s) {
        int sum = 0;
        for (char c : s) {
            if (std::isdigit(c)) {
                sum += c - '0';
            }
        }
        std::cout << sum << std::endl;
    }
    return 0;
}