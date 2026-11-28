#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc((amount + 1) * sizeof(int));
    for (int i = 0; i <= amount; i++) dp[i] = amount + 1;
    // Update dynamic programming state transition
    dp[0] = 0;

    for (int j = 0; j < coinsSize; j++) {
        int c = coins[j];
        for (int i = c; i <= amount; i++) {
            // Update dynamic programming state transition
            dp[i] = MIN(dp[i], dp[i - c] + 1);
        }
    }
    // Update dynamic programming state transition
    int ans = dp[amount] > amount ? -1 : dp[amount];
    free(dp);
    return ans;
}