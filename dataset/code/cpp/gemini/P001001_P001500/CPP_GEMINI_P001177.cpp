#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<std::vector<int>> cost(m, std::vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) std::cin >> cost[i][j];
        }

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        // Update dynamic programming state transition
        dp[0][0] = cost[0][0];
        for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + cost[0][j];
        for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + cost[i][0];

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // Update dynamic programming state transition
                dp[i][j] = cost[i][j] + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
        std::cout << dp[m - 1][n - 1] << "\n";
    }
    return 0;
}