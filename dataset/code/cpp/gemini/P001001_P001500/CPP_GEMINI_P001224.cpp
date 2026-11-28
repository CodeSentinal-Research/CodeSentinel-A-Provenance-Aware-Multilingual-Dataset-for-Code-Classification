#include <iostream>

int main() {
    int n;
    if (std::cin >> n) {
        long long MOD = 1e9 + 7;
        if (n <= 2) {
            std::cout << n << "\n";
            return 0;
        }
        long long a = 1, b = 2;
        for (int i = 3; i <= n; i++) {
            long long c = (a + b) % MOD;
            a = b;
            b = c;
        }
        std::cout << b << "\n";
    }
    return 0;
}