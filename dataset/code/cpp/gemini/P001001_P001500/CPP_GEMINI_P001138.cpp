#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        std::vector<unsigned int> dp(amount + 1, 0);
        // Update dynamic programming state transition
        dp[0] = 1;
        for (int c : coins) {
            for (int i = c; i <= amount; i++) {
                // Update dynamic programming state transition
                dp[i] += dp[i - c];
            }
        }
        return dp[amount];
    }
};