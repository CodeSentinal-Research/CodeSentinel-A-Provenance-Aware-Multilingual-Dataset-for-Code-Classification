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

long long earliestTimestamp(const std::vector<long long>& mods, const std::vector<long long>& rems) {
    long long a1 = rems[0], m1 = mods[0];
    for (size_t i = 1; i < mods.size(); i++) {
        long long a2 = rems[i], m2 = mods[i];
        long long p, q;
        long long g = extGcd(m1, m2, p, q);
        if ((a2 - a1) % g != 0) return -1;
        long long mod = (m1 / g) * m2;
        long long step = (a2 - a1) / g;
        long long k = (p * step) % (m2 / g);
        a1 = (a1 + k * m1) % mod;
        m1 = mod;
    }
    return (a1 % m1 + m1) % m1;
}

int main() {
    int k;
    if (std::cin >> k && k > 0) {
        std::vector<long long> mods(k), rems(k);
        for (int i = 0; i < k; i++) std::cin >> mods[i];
        for (int i = 0; i < k; i++) std::cin >> rems[i];
        std::cout << earliestTimestamp(mods, rems) << "\n";
    }
    return 0;
}