#include <iostream>
#include <iomanip>
#include <cmath>

double nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;
    double ans = 1;
    for (int i = 1; i <= r; i++) {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}

int main() {
    int n, k;
    double p;
    if (std::cin >> n >> k >> p) {
        double ans = nCr(n, k) * std::pow(p, k) * std::pow(1.0 - p, n - k);
        std::cout << std::fixed << std::setprecision(6) << ans << "\n";
    }
    return 0;
}