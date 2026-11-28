#include <iostream>
#include <vector>
using namespace std;

vector<long long> getPrimeFactors(long long n) {
    vector<long long> factors;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

long long countCoprime(long long N, long long L, long long R) {
    // Count numbers in [L, R] coprime to N
    // Use Inclusion-Exclusion on prime factors of N
    vector<long long> primes = getPrimeFactors(N);
    int k = primes.size();
    long long count = 0;
    
    auto countDivisible = [&](long long limit, long long d) -> long long {
        return limit / d;
    };
    
    for (int mask = 0; mask < (1 << k); ++mask) {
        long long prod = 1;
        int bits = 0;
        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                prod *= primes[i];
                bits++;
            }
        }
        long long term = countDivisible(R, prod) - countDivisible(L - 1, prod);
        if (bits % 2 == 0) count += term;
        else count -= term;
    }
    
    return count;
}

int main() {
    long long N, L, R;
    cin >> N >> L >> R;
    cout << countCoprime(N, L, R) << endl;
    return 0;
}
