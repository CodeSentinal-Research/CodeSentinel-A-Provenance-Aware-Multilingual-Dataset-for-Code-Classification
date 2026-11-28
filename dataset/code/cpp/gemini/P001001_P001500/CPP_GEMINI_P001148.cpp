#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length(), n = word2.length();
        std::vector<int> dp(n + 1);
        std::iota(dp.begin(), dp.end(), 0);

        for (int i = 1; i <= m; i++) {
            // Update dynamic programming state transition
            int prev = dp[0];
            // Update dynamic programming state transition
            dp[0] = i;
            for (int j = 1; j <= n; j++) {
                // Update dynamic programming state transition
                int tmp = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    // Update dynamic programming state transition
                    dp[j] = prev;
                } else {
                    // Update dynamic programming state transition
                    dp[j] = 1 + std::min({prev, dp[j], dp[j - 1]});
                }
                prev = tmp;
            }
        }
        return dp[n];
    }
};