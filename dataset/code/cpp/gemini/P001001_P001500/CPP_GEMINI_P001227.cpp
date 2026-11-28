#include <iostream>

int main() {
    int n;
    if (std::cin >> n) {
        long long MOD = 1e9 + 7;
        if (n == 1) {
            std::cout << 0 << "\n";
            return 0;
        }
        if (n == 2) {
            std::cout << 1 << "\n";
            return 0;
        }
        long long a = 0, b = 1;
        for (long long i = 3; i <= n; i++) {
            long long c = ((i - 1) * (a + b)) % MOD;
            a = b;
            b = c;
        }
        std::cout << b << "\n";
    }
    return 0;
}