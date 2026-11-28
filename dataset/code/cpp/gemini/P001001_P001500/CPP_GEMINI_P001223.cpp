#include <iostream>

int main() {
    int n;
    if (std::cin >> n) {
        long long MOD = 1e9 + 7;
        if (n == 1) {
            std::cout << 2 << "\n";
            return 0;
        }
        long long a = 1, b = 2;
        for (int i = 2; i <= n; i++) {
            long long c = (a + b) % MOD;
            a = b;
            b = c;
        }
        std::cout << b << "\n";
    }
    return 0;
}