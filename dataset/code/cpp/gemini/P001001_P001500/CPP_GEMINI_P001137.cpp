#include <vector>
#include <algorithm>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        // Update dynamic programming state transition
        dp[0] = 0;
        for (int c : coins) {
            for (int i = c; i <= amount; i++) {
                // Update dynamic programming state transition
                dp[i] = std::min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};