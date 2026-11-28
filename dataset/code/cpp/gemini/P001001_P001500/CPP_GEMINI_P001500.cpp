#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestPalindromeSubseq(std::string s) {
        int n = s.length();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            // Update dynamic programming state transition
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    // Update dynamic programming state transition
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    // Update dynamic programming state transition
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};