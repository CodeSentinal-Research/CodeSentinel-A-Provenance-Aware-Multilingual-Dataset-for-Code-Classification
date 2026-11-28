#include <iostream>

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
long long extGcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    long long r1, m1, r2, m2;
    if (std::cin >> r1 >> m1 >> r2 >> m2) {
        long long p, q;
        long long g = extGcd(m1, m2, p, q);
        if ((r2 - r1) % g != 0) {
            std::cout << -1 << "\n";
        } else {
            long long mod = (m1 / g) * m2;
            long long step = (r2 - r1) / g;
            long long k = (p * step) % (m2 / g);
            long long ans = (r1 + k * m1) % mod;
            std::cout << (ans % mod + mod) % mod << " " << mod << "\n";
        }
    }
    return 0;
}