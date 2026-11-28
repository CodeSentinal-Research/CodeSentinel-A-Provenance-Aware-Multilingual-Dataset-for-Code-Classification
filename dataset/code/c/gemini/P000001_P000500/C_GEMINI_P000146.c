#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return 0;
    int m = matrixSize, n = matrixColSize[0];
    // Update dynamic programming state transition
    int dp[505][505] = {0};
    int maxSide = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i - 1][j - 1] == '1' || matrix[i - 1][j - 1] == 1) {
                // Update dynamic programming state transition
                dp[i][j] = MIN(dp[i - 1][j], MIN(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                // Update dynamic programming state transition
                maxSide = MAX(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}