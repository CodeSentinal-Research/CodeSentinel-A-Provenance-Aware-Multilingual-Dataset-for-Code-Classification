#include <iostream>
#include <string>
#include <vector>
int main() {
    std::string s, p;
    if (std::cin >> s >> p) {
        int n = s.length(), m = p.length();
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
        // Update dynamic programming state transition
        dp[0][0] = true;
        for (int j = 2; j <= m; j += 2) {
            // Update dynamic programming state transition
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    // Update dynamic programming state transition
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        // Update dynamic programming state transition
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                        // Update dynamic programming state transition
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        std::cout << (dp[n][m] ? "true" : "false") << std::endl;
    }
    return 0;
}