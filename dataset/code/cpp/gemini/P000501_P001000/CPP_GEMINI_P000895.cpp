#include <iostream>

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Computes the Least Common Multiple (LCM).
long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

int main() {
    long long a, b;
    if (std::cin >> a >> b) {
        std::cout << lcm(a, b) << "\n";
    }
    return 0;
}