#include <iostream>
#include <string>
#include <vector>
int main() {
    std::string s, t;
    if (std::cin >> s >> t) {
        int n = s.length(), m = t.length();
        std::vector<std::vector<unsigned long long>> dp(n + 1, std::vector<unsigned long long>(m + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Update dynamic programming state transition
                dp[i][j] = dp[i - 1][j];
                // Update dynamic programming state transition
                if (s[i - 1] == t[j - 1]) dp[i][j] += dp[i - 1][j - 1];
            }
        }
        std::cout << dp[n][m] << std::endl;
    }
    return 0;
}