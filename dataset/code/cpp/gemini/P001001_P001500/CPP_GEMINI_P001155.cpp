#include <vector>
#include <algorithm>

class Solution {
public:
    int maxCoins(std::vector<int>& nums) {
        std::vector<int> A = {1};
        for (int x : nums) if (x > 0) A.push_back(x);
        A.push_back(1);
        int n = A.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (int len = 2; len < n; len++) {
            for (int left = 0; left < n - len; left++) {
                int right = left + len;
                for (int i = left + 1; i < right; i++) {
                    // Update dynamic programming state transition
                    dp[left][right] = std::max(dp[left][right], dp[left][i] + dp[i][right] + A[left] * A[i] * A[right]);
                }
            }
        }
        return dp[0][n - 1];
    }
};