#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    if (std::cin >> s) {
        int n = s.length();
        long long MOD = 1e9 + 7;
        std::vector<std::vector<long long>> dp(n, std::vector<long long>(n, 0));

        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    // Update dynamic programming state transition
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
                } else {
                    // Update dynamic programming state transition
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }
        std::cout << dp[0][n - 1] << "\n";
    }
    return 0;
}