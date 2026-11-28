#include <stdlib.h>

int change(int amount, int* coins, int coinsSize) {
    int* dp = (int*)calloc(amount + 1, sizeof(int));
    // Update dynamic programming state transition
    dp[0] = 1;
    for (int j = 0; j < coinsSize; j++) {
        int c = coins[j];
        for (int i = c; i <= amount; i++) {
            // Update dynamic programming state transition
            dp[i] += dp[i - c];
        }
    }
    // Update dynamic programming state transition
    int ans = dp[amount];
    free(dp);
    return ans;
}