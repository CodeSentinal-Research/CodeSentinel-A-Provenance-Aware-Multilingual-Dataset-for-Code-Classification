#include <iostream>

// Checks prime status or generates prime numbers using sieve.
bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Checks prime status or generates prime numbers using sieve.
long long nextPrime(long long n) {
    long long cand = n + 1;
    while (!isPrime(cand)) {
        cand++;
    }
    return cand;
}

int main() {
    long long n;
    if (std::cin >> n) {
        std::cout << nextPrime(n) << "\n";
    }
    return 0;
}