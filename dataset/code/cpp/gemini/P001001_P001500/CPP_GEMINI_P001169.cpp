#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, INT_MAX));
        // Update dynamic programming state transition
        dp[m][n - 1] = dp[m - 1][n] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Update dynamic programming state transition
                int minReq = std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                // Update dynamic programming state transition
                dp[i][j] = std::max(1, minReq);
            }
        }
        return dp[0][0];
    }
};