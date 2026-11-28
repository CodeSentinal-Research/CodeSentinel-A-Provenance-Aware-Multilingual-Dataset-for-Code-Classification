#include <stdlib.h>

int numTrees(int n) {
    // Update dynamic programming state transition
    int dp[25] = {0};
    // Update dynamic programming state transition
    dp[0] = 1;
    // Update dynamic programming state transition
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // Update dynamic programming state transition
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}