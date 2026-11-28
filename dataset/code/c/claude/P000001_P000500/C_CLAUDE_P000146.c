int maximalSquare(char** matrix, int m, int n) {
    int** dp = (int**)calloc(m, sizeof(int*));
    for (int i = 0; i < m; i++) dp[i] = (int*)calloc(n, sizeof(int));
    int side = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else {
                    int mn = dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
                    if (dp[i-1][j-1] < mn) mn = dp[i-1][j-1];
                    dp[i][j] = mn + 1;
                }
                if (dp[i][j] > side) side = dp[i][j];
            }
        }
    }
    for (int i = 0; i < m; i++) free(dp[i]);
    free(dp);
    return side * side;
}
