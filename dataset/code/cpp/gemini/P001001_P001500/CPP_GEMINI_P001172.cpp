#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int n = obstacleGrid[0].size();
        std::vector<long long> dp(n, 0);
        // Update dynamic programming state transition
        dp[0] = 1;
        for (const auto& row : obstacleGrid) {
            for (int j = 0; j < n; j++) {
                if (row[j] == 1) {
                    // Update dynamic programming state transition
                    dp[j] = 0;
                } else if (j > 0) {
                    // Update dynamic programming state transition
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};