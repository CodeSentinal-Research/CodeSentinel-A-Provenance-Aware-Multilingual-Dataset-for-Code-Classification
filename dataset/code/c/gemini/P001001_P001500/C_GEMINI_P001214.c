#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int strangePrinter(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int i = n - 1; i >= 0; i--) {
        // Update dynamic programming state transition
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                // Update dynamic programming state transition
                dp[i][j] = dp[i][j - 1];
            } else {
                int minTurns = 1000000000;
                for (int k = i; k < j; k++) {
                    // Update dynamic programming state transition
                    minTurns = MIN(minTurns, dp[i][k] + dp[k + 1][j]);
                }
                // Update dynamic programming state transition
                dp[i][j] = minTurns;
            }
        }
    }
    return dp[0][n - 1];
}