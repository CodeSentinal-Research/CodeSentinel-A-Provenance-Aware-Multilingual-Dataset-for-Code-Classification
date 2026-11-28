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
    long long a, b;
    if (std::cin >> a >> b) {
        long long rawX, rawY;
        long long g = extGcd(a, b, rawX, rawY);
        long long stepX = b / g;
        long long x = (rawX % stepX + stepX) % stepX;
        if (x == 0) x += stepX;
        long long y = (g - a * x) / b;
        std::cout << x << " " << y << "\n";
    }
    return 0;
}