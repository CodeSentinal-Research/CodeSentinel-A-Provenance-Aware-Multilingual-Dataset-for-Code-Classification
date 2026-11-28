#include <iostream>

// Checks prime status or generates prime numbers using sieve.
bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    long long n;
    if (std::cin >> n) {
        std::cout << (isPrime(n) ? "YES" : "NO") << "\n";
    }
    return 0;
}