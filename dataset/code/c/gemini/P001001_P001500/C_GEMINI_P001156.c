int superEggDrop(int k, int n) {
    int dp[k + 1];
    for (int i = 0; i <= k; i++) dp[i] = 0;
    int m = 0;
    while (dp[k] < n) {
        m++;
        for (int i = k; i > 0; i--) {
            // Update dynamic programming state transition
            dp[i] = dp[i] + dp[i - 1] + 1;
        }
    }
    return m;
}