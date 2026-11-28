#include <iostream>
#include <vector>
int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<int>> grid(n, std::vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) std::cin >> grid[i][j];
        }
        if (grid[0][0] == 0 || grid[n - 1][m - 1] == 0) { std::cout << 0 << std::endl; return 0; }
        std::vector<std::vector<long long>> dp(n, std::vector<long long>(m, 0));
        // Update dynamic programming state transition
        dp[0][0] = 1;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 0) continue;
                // Update dynamic programming state transition
                if (r > 0) dp[r][c] += dp[r - 1][c];
                // Update dynamic programming state transition
                if (c > 0) dp[r][c] += dp[r][c - 1];
            }
        }
        std::cout << dp[n - 1][m - 1] << std::endl;
    }
    return 0;
}