#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lcs(int x, int y, char* s1, char* s2) {
    // Update dynamic programming state transition
    int dp[1005][1005] = {0};
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // Update dynamic programming state transition
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Update dynamic programming state transition
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[x][y];
}