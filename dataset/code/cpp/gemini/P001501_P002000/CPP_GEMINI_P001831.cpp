#include <vector>

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dp(n + 1, 0);
        // Update dynamic programming state transition
        dp[0] = 1;
        // Update dynamic programming state transition
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                // Update dynamic programming state transition
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};