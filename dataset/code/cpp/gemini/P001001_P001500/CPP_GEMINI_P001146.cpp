#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int m = text1.length(), n = text2.length();
        std::vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int prev = 0;
            for (int j = 1; j <= n; j++) {
                // Update dynamic programming state transition
                int tmp = dp[j];
                if (text1[i - 1] == text2[j - 1]) {
                    // Update dynamic programming state transition
                    dp[j] = prev + 1;
                } else {
                    // Update dynamic programming state transition
                    dp[j] = std::max(dp[j], dp[j - 1]);
                }
                prev = tmp;
            }
        }
        return dp[n];
    }
};