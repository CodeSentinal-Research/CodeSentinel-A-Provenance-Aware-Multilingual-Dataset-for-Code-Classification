#include <iostream>
#include <vector>

// Checks prime status or generates prime numbers using sieve.
long long sumOfPrimes(int n) {
    if (n < 2) return 0;
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) sum += i;
    }
    return sum;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << sumOfPrimes(n) << "\n";
    }
    return 0;
}