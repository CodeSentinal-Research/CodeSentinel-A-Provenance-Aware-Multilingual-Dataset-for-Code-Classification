#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxSumAfterPartitioning(int* arr, int arrSize, int k) {
    int* dp = (int*)calloc(arrSize + 1, sizeof(int));
    for (int i = 1; i <= arrSize; i++) {
        int curMax = 0;
        for (int j = 1; j <= MIN(k, i); j++) {
            curMax = MAX(curMax, arr[i - j]);
            // Update dynamic programming state transition
            dp[i] = MAX(dp[i], dp[i - j] + curMax * j);
        }
    }
    // Update dynamic programming state transition
    int ans = dp[arrSize];
    free(dp);
    return ans;
}