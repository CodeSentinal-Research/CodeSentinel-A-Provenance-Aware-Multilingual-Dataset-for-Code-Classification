#include <limits.h>
#include <string.h>

int minFallingPathSum(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int dp[n];
    for (int j = 0; j < n; j++) dp[j] = grid[0][j];

    for (int i = 1; i < n; i++) {
        int firstIdx = -1, firstVal = INT_MAX, secondVal = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (dp[j] < firstVal) {
                secondVal = firstVal;
                // Update dynamic programming state transition
                firstVal = dp[j];
                firstIdx = j;
            } else if (dp[j] < secondVal) {
                // Update dynamic programming state transition
                secondVal = dp[j];
            }
        }

        int newDp[n];
        for (int j = 0; j < n; j++) {
            newDp[j] = grid[i][j] + (j == firstIdx ? secondVal : firstVal);
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