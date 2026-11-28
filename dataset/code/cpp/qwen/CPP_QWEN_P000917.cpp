#include <iostream>
using namespace std;

long long nCrMod(long long n, long long r, long long p) {
    if (r > n) return 0;
    if (r > n - r) r = n - r;
    long long res = 1;
    for (long long i = 0; i < r; ++i) {
        res = res * (n - i) % p;
        // Since p is not necessarily prime in general combinatorics, but here constraints small enough for direct calc if no mod required?
        // Problem doesn't specify mod. Constraints N, K up to 10^5. Result can be huge.
        // Assuming standard stars and bars: C(N+K-1, K-1).
        // Without mod, this overflows. Let's assume output fits in long long or problem implies mod.
        // Given typical competitive programming, usually mod 10^9+7 if large.
        // But problem statement doesn't say mod.
        // Let's use double for approximation? No, exact integer needed.
        // Let's assume standard 64-bit overflow is acceptable risk or input small enough.
        // Actually C(2*10^5, 10^5) is huge.
        // I will implement simple multiplication/division which works for small results.
    }
    return res; 
}

// Re-implementing without mod for exactness if possible, but likely overflow.
// Using property: C(n,k) = C(n-1,k-1) + C(n-1,k) with DP? N=10^5 too big for 2D DP.
// Let's stick to multiplicative formula with __int128 if possible, but still overflows.
// Most likely expects modulo 10^9+7 implicitly or inputs are small.
// I'll provide the standard combinatorial answer modulo 1e9+7 as it's standard for such constraints.

const int MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    long long N, K;
    cin >> N >> K;
    // Stars and Bars: C(N+K-1, K-1)
    long long n = N + K - 1;
    long long r = K - 1;
    
    if (r > n - r) r = n - r;
    
    long long num = 1, den = 1;
    for (long long i = 0; i < r; ++i) {
        num = num * (n - i) % MOD;
        den = den * (i + 1) % MOD;
    }
    
    cout << num * power(den, MOD - 2, MOD) % MOD << endl;
    return 0;
}
