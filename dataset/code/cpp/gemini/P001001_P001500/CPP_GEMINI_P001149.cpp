#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s1, s2;
    if (std::cin >> s1 >> s2) {
        int m = s1.length(), n = s2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    // Update dynamic programming state transition
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // Update dynamic programming state transition
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        std::cout << m + n - dp[m][n] << "\n";
    }
    return 0;
}