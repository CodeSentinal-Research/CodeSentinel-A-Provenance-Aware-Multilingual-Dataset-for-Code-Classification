#include <string>
#include <vector>

class Solution {
public:
    int numberOfArrays(std::string s, int k) {
        int n = s.length();
        long long MOD = 1e9 + 7;
        std::vector<long long> dp(n + 1, 0);
        // Update dynamic programming state transition
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') continue;
            long long cur = 0;
            for (int j = i; j < n; j++) {
                cur = cur * 10 + (s[j] - '0');
                if (cur > k) break;
                // Update dynamic programming state transition
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
            }
        }
        return dp[0];
    }
};