#include <string.h>

#define MOD 1000000007LL

int numberOfArrays(char* s, int k) {
    int n = strlen(s);
    long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
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
    return (int)dp[0];
}