#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestPalindromeSubseq(std::string s) {
        int n = s.length();
        std::vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            std::vector<int> newDp(n, 0);
            newDp[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    // Update dynamic programming state transition
                    newDp[j] = dp[j - 1] + 2;
                } else {
                    // Update dynamic programming state transition
                    newDp[j] = std::max(dp[j], newDp[j - 1]);
                }
            }
            dp = std::move(newDp);
        }
        return dp[n - 1];
    }
};