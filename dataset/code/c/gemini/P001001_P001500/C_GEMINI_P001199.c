#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;
    int m = matrixSize, n = matrixColSize[0];
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    int maxSide = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i - 1][j - 1] == '1') {
                // Update dynamic programming state transition
                dp[i][j] = 1 + MIN(dp[i - 1][j], MIN(dp[i][j - 1], dp[i - 1][j - 1]));
                // Update dynamic programming state transition
                if (dp[i][j] > maxSide) maxSide = dp[i][j];
            }
        }
    }
    return maxSide * maxSide;
}