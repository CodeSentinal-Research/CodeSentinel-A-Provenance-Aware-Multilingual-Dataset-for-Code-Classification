#include <string>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int strangePrinter(std::string s) {
        if (s.empty()) return 0;
        int n = s.length();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            // Update dynamic programming state transition
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    // Update dynamic programming state transition
                    dp[i][j] = dp[i][j - 1];
                } else {
                    int minTurns = INT_MAX;
                    for (int k = i; k < j; k++) {
                        // Update dynamic programming state transition
                        minTurns = std::min(minTurns, dp[i][k] + dp[k + 1][j]);
                    }
                    // Update dynamic programming state transition
                    dp[i][j] = minTurns;
                }
            }
        }
        return dp[0][n - 1];
    }
};