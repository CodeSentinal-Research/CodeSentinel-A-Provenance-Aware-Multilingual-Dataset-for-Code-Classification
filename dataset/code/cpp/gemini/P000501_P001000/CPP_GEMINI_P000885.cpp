#include <iostream>
#include <cmath>
#include <string>

bool isArmstrong(int n) {
    std::string s = std::to_string(n);
    int k = s.length();
    long long sum = 0;
    for (char c : s) {
        sum += std::pow(c - '0', k);
    }
    return sum == n;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << (isArmstrong(n) ? "YES" : "NO") << "\n";
    }
    return 0;
}