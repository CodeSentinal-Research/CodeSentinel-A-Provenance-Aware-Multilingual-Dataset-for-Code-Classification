#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lcs(int x, int y, std::string s1, std::string s2) {
        std::vector<std::vector<int>> dp(x + 1, std::vector<int>(y + 1, 0));
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    // Update dynamic programming state transition
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // Update dynamic programming state transition
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[x][y];
    }
};