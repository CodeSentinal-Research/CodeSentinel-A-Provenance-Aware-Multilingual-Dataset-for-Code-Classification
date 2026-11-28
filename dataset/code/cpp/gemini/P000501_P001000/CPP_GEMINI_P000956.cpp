#include <iostream>
#include <vector>
#include <algorithm>

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

int main() {
    long long a, b, m;
    if (std::cin >> a >> b >> m) {
        long long x, y;
        long long g = extGcd(a, m, x, y);
        if (b % g != 0) {
            std::cout << -1 << "\n";
        } else {
            long long x0 = (x * (b / g)) % m;
            x0 = (x0 + m) % m;
            long long step = m / g;
            std::vector<long long> ans;
            for (int i = 0; i < g; i++) {
                ans.push_back((x0 + i * step) % m);
            }
            std::sort(ans.begin(), ans.end());
            for (size_t i = 0; i < ans.size(); i++) {
                std::cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}