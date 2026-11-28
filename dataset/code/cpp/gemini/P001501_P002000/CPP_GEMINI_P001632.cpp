#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n, k;
    if (std::cin >> m >> n >> k) {
        std::vector<std::vector<int>> p(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val;
                std::cin >> val;
                p[i + 1][j + 1] = val + p[i][j + 1] + p[i + 1][j] - p[i][j];
            }
        }

        int maxSide = 0;
        for (int side = 1; side <= std::min(m, n); side++) {
            for (int i = 0; i <= m - side; i++) {
                for (int j = 0; j <= n - side; j++) {
                    int sum = p[i + side][j + side] - p[i][j + side] - p[i + side][j] + p[i][j];
                    if (sum <= k) maxSide = std::max(maxSide, side);
                }
            }
        }
        std::cout << maxSide << "\n";
    }
    return 0;
}