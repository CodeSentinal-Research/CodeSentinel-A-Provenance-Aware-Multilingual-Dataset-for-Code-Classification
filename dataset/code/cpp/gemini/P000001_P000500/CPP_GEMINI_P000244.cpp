#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumPath(int N, std::vector<std::vector<int>>& Matrix) {
        std::vector<std::vector<int>> dp = Matrix;

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // Update dynamic programming state transition
                int up = dp[i - 1][j];
                // Update dynamic programming state transition
                int upLeft = (j > 0 ? dp[i - 1][j - 1] : 0);
                // Update dynamic programming state transition
                int upRight = (j < N - 1 ? dp[i - 1][j + 1] : 0);
                // Update dynamic programming state transition
                dp[i][j] += std::max({up, upLeft, upRight});
            }
        }

        return *std::max_element(dp[N - 1].begin(), dp[N - 1].end());
    }
};