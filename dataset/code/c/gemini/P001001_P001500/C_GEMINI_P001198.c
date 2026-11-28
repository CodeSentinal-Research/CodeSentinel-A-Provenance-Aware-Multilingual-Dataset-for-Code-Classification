#define MIN(a, b) ((a) < (b) ? (a) : (b))

int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0];
    int dp[m][n];
    int total = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    // Update dynamic programming state transition
                    dp[i][j] = 1;
                } else {
                    // Update dynamic programming state transition
                    dp[i][j] = 1 + MIN(dp[i - 1][j], MIN(dp[i][j - 1], dp[i - 1][j - 1]));
                }
                // Update dynamic programming state transition
                total += dp[i][j];
            } else {
                // Update dynamic programming state transition
                dp[i][j] = 0;
            }
        }
    }
    return total;
}