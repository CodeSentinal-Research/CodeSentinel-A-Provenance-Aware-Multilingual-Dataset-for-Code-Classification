#include <iostream>
#include <string>
#include <cctype>

bool isDivisibleBy3(const std::string& s) {
    int sum = 0;
    for (char c : s) {
        if (isdigit(c)) sum += (c - '0');
    }
    return sum % 3 == 0;
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::cout << (isDivisibleBy3(s) ? "YES" : "NO") << "\n";
    }
    return 0;
}