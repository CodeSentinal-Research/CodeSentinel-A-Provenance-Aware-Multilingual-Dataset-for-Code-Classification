#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;
    int dp[n + 3];
    memset(dp, 0, sizeof(dp));

    for (int i = n - 1; i >= 0; i--) {
        int take = 0;
        // Update dynamic programming state transition
        dp[i] = -1000000000;
        for (int k = 1; k <= 3; k++) {
            if (i + k <= n) {
                take += stoneValue[i + k - 1];
                // Update dynamic programming state transition
                dp[i] = MAX(dp[i], take - dp[i + k]);
            }
        }
    }
    if (dp[0] > 0) return "Alice";
    if (dp[0] < 0) return "Bob";
    return "Tie";
}