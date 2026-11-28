#include <iostream>
#include <vector>

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

long long crt(const std::vector<long long>& num, const std::vector<long long>& rem) {
    long long prod = 1;
    for (long long n : num) prod *= n;
    long long result = 0;
    for (size_t i = 0; i < num.size(); i++) {
        long long pp = prod / num[i];
        long long x, y;
        extGcd(pp, num[i], x, y);
        long long inv = (x % num[i] + num[i]) % num[i];
        result = (result + rem[i] * pp % prod * inv) % prod;
    }
    return result;
}

int main() {
    int k;
    if (std::cin >> k && k > 0) {
        std::vector<long long> num(k), rem(k);
        for (int i = 0; i < k; i++) std::cin >> num[i];
        for (int i = 0; i < k; i++) std::cin >> rem[i];
        std::cout << crt(num, rem) << "\n";
    }
    return 0;
}