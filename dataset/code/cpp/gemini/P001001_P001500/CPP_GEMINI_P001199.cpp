#include <vector>
#include <algorithm>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        int maxSide = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    // Update dynamic programming state transition
                    dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    // Update dynamic programming state transition
                    maxSide = std::max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }
};