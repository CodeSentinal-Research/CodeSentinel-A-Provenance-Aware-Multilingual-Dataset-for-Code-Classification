#include <iostream>

int countLeadingZeros(unsigned int n) {
    if (n == 0) return 32;
    return __builtin_clz(n);
}

int main() {
    unsigned int n;
    if (std::cin >> n) {
        std::cout << countLeadingZeros(n) << "\n";
    }
    return 0;
}