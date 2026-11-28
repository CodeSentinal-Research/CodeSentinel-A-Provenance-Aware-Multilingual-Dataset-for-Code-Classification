#include <iostream>
#include <algorithm>

int main() {
    int n, m, r, c;
    if (std::cin >> n >> m >> r >> c) {
        int ans = std::max(r - 1, n - r) + std::max(c - 1, m - c);
        std::cout << ans << "\n";
    }
    return 0;
}