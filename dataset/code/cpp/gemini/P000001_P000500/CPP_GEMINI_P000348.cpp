#include <iostream>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        const int MOD = 1e9 + 7;
        std::vector<std::vector<long long>> dp(2, std::vector<long long>(3, 0));
        // Update dynamic programming state transition
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            std::vector<std::vector<long long>> next_dp(2, std::vector<long long>(3, 0));
            for (int a = 0; a < 2; a++) {
                for (int l = 0; l < 3; l++) {
                    // Update dynamic programming state transition
                    long long val = dp[a][l];
                    if (!val) continue;
                    // 'P'
                    next_dp[a][0] = (next_dp[a][0] + val) % MOD;
                    // 'A'
                    if (a == 0) next_dp[1][0] = (next_dp[1][0] + val) % MOD;
                    // 'L'
                    if (l < 2) next_dp[a][l + 1] = (next_dp[a][l + 1] + val) % MOD;
                }
            }
            dp = next_dp;
        }
        long long total = 0;
        for (int a = 0; a < 2; a++) {
            for (int l = 0; l < 3; l++) total = (total + dp[a][l]) % MOD;
        }
        std::cout << total << std::endl;
    }
    return 0;
}