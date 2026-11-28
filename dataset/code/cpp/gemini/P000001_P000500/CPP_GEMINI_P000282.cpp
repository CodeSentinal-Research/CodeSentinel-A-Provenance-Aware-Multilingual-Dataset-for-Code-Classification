#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestCommonSubstr(std::string S1, std::string S2, int n, int m) {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        int res = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (S1[i - 1] == S2[j - 1]) {
                    // Update dynamic programming state transition
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    // Update dynamic programming state transition
                    res = std::max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};