#define MOD 1000000007LL

int numTilings(int n) {
    if (n <= 2) return n;
    long long dp[n + 1];
    // Update dynamic programming state transition
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        // Update dynamic programming state transition
        dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
    }
    return (int)dp[n];
}