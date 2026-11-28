#include <iostream>
#include <numeric>

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    long long num, den;
    if (std::cin >> num >> den) {
        long long g = gcd(num, den);
        std::cout << (num / g) << " " << (den / g) << "\n";
    }
    return 0;
}