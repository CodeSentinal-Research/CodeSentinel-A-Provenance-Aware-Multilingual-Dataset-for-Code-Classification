#include <iostream>
#include <vector>

int main() {
    int n, k, target;
    if (std::cin >> n >> k >> target) {
        long long MOD = 1e9 + 7;
        std::vector<long long> dp(target + 1, 0);
        // Update dynamic programming state transition
        dp[0] = 1;

        for (int step = 0; step < n; step++) {
            std::vector<long long> newDp(target + 1, 0);
            for (int j = 1; j <= target; j++) {
                for (int face = 1; face <= k; face++) {
                    if (j >= face) {
                        // Update dynamic programming state transition
                        newDp[j] = (newDp[j] + dp[j - face]) % MOD;
                    }
                }
            }
            dp = std::move(newDp);
        }
        std::cout << dp[target] << "\n";
    }
    return 0;
}