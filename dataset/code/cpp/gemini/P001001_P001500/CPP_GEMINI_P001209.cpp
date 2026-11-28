#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        std::vector<int> dp(n + 3, 0);

        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            // Update dynamic programming state transition
            dp[i] = INT_MIN;
            for (int k = 1; k <= 3; k++) {
                if (i + k <= n) {
                    take += stoneValue[i + k - 1];
                    // Update dynamic programming state transition
                    dp[i] = std::max(dp[i], take - dp[i + k]);
                }
            }
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};