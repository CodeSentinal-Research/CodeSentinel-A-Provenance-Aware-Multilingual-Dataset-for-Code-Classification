#include <iostream>
#include <vector>

// Checks prime status or generates prime numbers using sieve.
long long countCoprime(long long n, long long r) {
    std::vector<long long> primes;
    long long temp = n;
    for (long long d = 2; d * d <= temp; d++) {
        if (temp % d == 0) {
            primes.push_back(d);
            while (temp % d == 0) temp /= d;
        }
    }
    if (temp > 1) primes.push_back(temp);

    int m = primes.size();
    long long divCount = 0;
    for (int mask = 1; mask < (1 << m); mask++) {
        long long prod = 1;
        int bits = 0;
        for (int i = 0; i < m; i++) {
            // If current bit is set, multiply base into result
            if ((mask >> i) & 1) {
                prod *= primes[i];
                bits++;
            }
        }
        // If current bit is set, multiply base into result
        if (bits % 2 == 1) divCount += r / prod;
        else divCount -= r / prod;
    }
    return r - divCount;
}

int main() {
    long long n, r;
    if (std::cin >> n >> r) {
        std::cout << countCoprime(n, r) << "\n";
    }
    return 0;
}