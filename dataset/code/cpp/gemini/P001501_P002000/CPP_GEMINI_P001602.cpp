#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        long long cur = 0, maxAbs = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            cur += x;
            maxAbs = std::max(maxAbs, std::abs(cur));
        }
        std::cout << maxAbs << "\n";
    }
    return 0;
}