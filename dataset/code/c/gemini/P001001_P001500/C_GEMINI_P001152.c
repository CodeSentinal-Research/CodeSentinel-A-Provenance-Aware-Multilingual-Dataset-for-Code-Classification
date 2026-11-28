#include <stdio.h>
#include <string.h>

#define MOD 1000000007LL

int main() {
    char s[1005];
    if (scanf("%s", s) == 1) {
        int n = strlen(s);
        long long dp[n][n];
        memset(dp, 0, sizeof(dp));

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
        printf("%lld\n", dp[0][n - 1]);
    }
    return 0;
}