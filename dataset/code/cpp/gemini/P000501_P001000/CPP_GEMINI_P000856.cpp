#include <iostream>

int countTrailingZeros(unsigned int n) {
    if (n == 0) return 32;
    return __builtin_ctz(n);
}

int main() {
    unsigned int n;
    if (std::cin >> n) {
        std::cout << countTrailingZeros(n) << "\n";
    }
    return 0;
}