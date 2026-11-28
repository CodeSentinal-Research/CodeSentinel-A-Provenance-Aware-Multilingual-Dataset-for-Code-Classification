#include <iostream>
#include <cmath>
#include <string>
int main() {
    int n;
    if (std::cin >> n) {
        std::string s = std::to_string(n);
        int p = s.length();
        int sum = 0;
        for (char c : s) {
            sum += std::pow(c - '0', p);
        }
        std::cout << (sum == n ? "Armstrong" : "Not Armstrong") << std::endl;
    }
    return 0;
}