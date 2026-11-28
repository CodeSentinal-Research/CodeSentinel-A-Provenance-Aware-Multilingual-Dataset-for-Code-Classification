#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    int dp[n];
    for (int j = 0; j < n; j++) dp[j] = matrix[0][j];

    for (int i = 1; i < n; i++) {
        int newDp[n];
        for (int j = 0; j < n; j++) {
            // Update dynamic programming state transition
            int best = dp[j];
            // Update dynamic programming state transition
            if (j > 0) best = MIN(best, dp[j - 1]);
            // Update dynamic programming state transition
            if (j < n - 1) best = MIN(best, dp[j + 1]);
            newDp[j] = matrix[i][j] + best;
        }
        memcpy(dp, newDp, sizeof(dp));
    }

    // Update dynamic programming state transition
    int minVal = dp[0];
    for (int j = 1; j < n; j++) {
        // Update dynamic programming state transition
        if (dp[j] < minVal) minVal = dp[j];
    }
    return minVal;
}