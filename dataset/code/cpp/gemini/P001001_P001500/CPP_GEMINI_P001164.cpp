#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumDeleteSum(std::string s1, std::string s2) {
        int m = s1.length(), n = s2.length();
        std::vector<int> dp(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            // Update dynamic programming state transition
            dp[j] = dp[j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= m; i++) {
            // Update dynamic programming state transition
            int prev = dp[0];
            // Update dynamic programming state transition
            dp[0] += s1[i - 1];
            for (int j = 1; j <= n; j++) {
                // Update dynamic programming state transition
                int tmp = dp[j];
                if (s1[i - 1] == s2[j - 1]) {
                    // Update dynamic programming state transition
                    dp[j] = prev;
                } else {
                    // Update dynamic programming state transition
                    dp[j] = std::min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
                }
                prev = tmp;
            }
        }
        return dp[n];
    }
};