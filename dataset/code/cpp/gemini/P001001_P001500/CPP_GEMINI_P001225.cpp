#include <vector>

class Solution {
public:
    int numTilings(int n) {
        long long MOD = 1e9 + 7;
        if (n <= 2) return n;
        std::vector<long long> dp(n + 1, 0);
        // Update dynamic programming state transition
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            // Update dynamic programming state transition
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
        }
        return dp[n];
    }
};