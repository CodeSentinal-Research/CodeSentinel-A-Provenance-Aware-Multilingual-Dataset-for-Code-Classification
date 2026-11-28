#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<std::vector<int>> mine(m, std::vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) std::cin >> mine[i][j];
        }

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; i++) dp[i][0] = mine[i][0];

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                // Update dynamic programming state transition
                int best = dp[i][j - 1];
                // Update dynamic programming state transition
                if (i > 0) best = std::max(best, dp[i - 1][j - 1]);
                // Update dynamic programming state transition
                if (i < m - 1) best = std::max(best, dp[i + 1][j - 1]);
                // Update dynamic programming state transition
                dp[i][j] = mine[i][j] + best;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) ans = std::max(ans, dp[i][n - 1]);
        std::cout << ans << "\n";
    }
    return 0;
}