#include <iostream>

// Calculates modular exponentiation (base^exp % mod) efficiently.
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << (isPowerOfTwo(n) ? "YES" : "NO") << "\n";
    }
    return 0;
}