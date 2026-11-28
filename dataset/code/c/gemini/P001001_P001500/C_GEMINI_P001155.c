#include <string.h>

int maxCoins(int* nums, int numsSize) {
    int A[numsSize + 2];
    int n = 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) A[n++] = nums[i];
    }
    A[0] = A[n++] = 1;

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int len = 2; len < n; len++) {
        for (int left = 0; left < n - len; left++) {
            int right = left + len;
            for (int i = left + 1; i < right; i++) {
                // Update dynamic programming state transition
                int coins = dp[left][i] + dp[i][right] + A[left] * A[i] * A[right];
                // Update dynamic programming state transition
                if (coins > dp[left][right]) dp[left][right] = coins;
            }
        }
    }
    return dp[0][n - 1];
}