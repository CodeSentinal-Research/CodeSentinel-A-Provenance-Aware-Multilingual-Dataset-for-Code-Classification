#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s1, s2;
    if (std::cin >> s1 >> s2) {
        int m = s1.length(), n = s2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        int maxLen = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    // Update dynamic programming state transition
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    // Update dynamic programming state transition
                    maxLen = std::max(maxLen, dp[i][j]);
                }
            }
        }
        std::cout << maxLen << "\n";
    }
    return 0;
}