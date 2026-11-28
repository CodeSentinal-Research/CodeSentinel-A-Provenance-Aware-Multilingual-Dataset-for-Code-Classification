#include <iostream>
#include <string>
#include <cctype>
int main() {
    std::string s;
    if (std::cin >> s) {
        long long prod = 1;
        for (char c : s) if (std::isdigit(c)) prod *= (c - '0');
        std::cout << prod << std::endl;
    }
    return 0;
}