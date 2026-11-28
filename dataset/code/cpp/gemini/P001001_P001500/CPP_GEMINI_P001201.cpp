#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<int> dp = grid[0];

        for (int i = 1; i < n; i++) {
            int firstIdx = -1, firstVal = INT_MAX, secondVal = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (dp[j] < firstVal) {
                    secondVal = firstVal;
                    // Update dynamic programming state transition
                    firstVal = dp[j];
                    firstIdx = j;
                } else if (dp[j] < secondVal) {
                    // Update dynamic programming state transition
                    secondVal = dp[j];
                }
            }

            std::vector<int> newDp(n);
            for (int j = 0; j < n; j++) {
                newDp[j] = grid[i][j] + (j == firstIdx ? secondVal : firstVal);
            }
            dp = std::move(newDp);
        }
        return *std::min_element(dp.begin(), dp.end());
    }
};