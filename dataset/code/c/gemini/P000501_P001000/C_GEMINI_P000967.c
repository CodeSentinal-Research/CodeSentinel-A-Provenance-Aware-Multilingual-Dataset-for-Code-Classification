#include <stdio.h>

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
long long extGcd(long long a, long long b, long long* x, long long* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extGcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return g;
}

long long earliestTimestamp(const long long mods[], const long long rems[], int k) {
    long long a1 = rems[0], m1 = mods[0];
    for (int i = 1; i < k; i++) {
        long long a2 = rems[i], m2 = mods[i];
        long long p, q;
        long long g = extGcd(m1, m2, &p, &q);
        if ((a2 - a1) % g != 0) return -1;
        long long mod = (m1 / g) * m2;
        long long step = (a2 - a1) / g;
        long long kv = (p * step) % (m2 / g);
        a1 = (a1 + kv * m1) % mod;
        m1 = mod;
    }
    return (a1 % m1 + m1) % m1;
}

int main() {
    int k;
    if (scanf("%d", &k) == 1 && k > 0) {
        long long mods[k], rems[k];
        for (int i = 0; i < k; i++) scanf("%lld", &mods[i]);
        for (int i = 0; i < k; i++) scanf("%lld", &rems[i]);
        printf("%lld\n", earliestTimestamp(mods, rems, k));
    }
    return 0;
}