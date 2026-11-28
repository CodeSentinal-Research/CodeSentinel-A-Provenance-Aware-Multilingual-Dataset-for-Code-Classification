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
    long long a, b, c;
    if (std::cin >> a >> b >> c) {
        long long x, y;
        long long g = extGcd(a, b, x, y);
        if (c % g != 0) {
            std::cout << "-1 -1\n";
        } else {
            long long f = c / g;
            std::cout << x * f << " " << y * f << "\n";
        }
    }
    return 0;
}