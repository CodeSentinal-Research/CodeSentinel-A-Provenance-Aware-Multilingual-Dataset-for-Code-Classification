#include <iostream>
#include <string>
#include <cmath>

bool isDivisibleBy11(const std::string& s) {
    int oddSum = 0, evenSum = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (i % 2 == 0) oddSum += (s[i] - '0');
        else evenSum += (s[i] - '0');
    }
    return std::abs(oddSum - evenSum) % 11 == 0;
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::cout << (isDivisibleBy11(s) ? "YES" : "NO") << "\n";
    }
    return 0;
}