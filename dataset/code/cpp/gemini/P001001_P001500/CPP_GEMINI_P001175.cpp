#include <vector>
#include <algorithm>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        std::vector<int> dp = matrix[0];

        for (int i = 1; i < n; i++) {
            std::vector<int> newDp(n);
            for (int j = 0; j < n; j++) {
                // Update dynamic programming state transition
                int best = dp[j];
                // Update dynamic programming state transition
                if (j > 0) best = std::min(best, dp[j - 1]);
                // Update dynamic programming state transition
                if (j < n - 1) best = std::min(best, dp[j + 1]);
                newDp[j] = matrix[i][j] + best;
            }
            dp = std::move(newDp);
        }
        return *std::min_element(dp.begin(), dp.end());
    }
};