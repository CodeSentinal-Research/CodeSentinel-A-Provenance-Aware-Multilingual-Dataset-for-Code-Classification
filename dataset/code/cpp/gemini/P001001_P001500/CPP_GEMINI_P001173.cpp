#include <vector>
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<int> dp(n);
        // Update dynamic programming state transition
        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++) dp[j] = dp[j - 1] + grid[0][j];

        for (int i = 1; i < m; i++) {
            // Update dynamic programming state transition
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                // Update dynamic programming state transition
                dp[j] = std::min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};