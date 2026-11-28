function countArrays(n) {
    if (n <= 1) return n;

    let dp = [0, 1, 2];

    for (let i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10000000007;
    }

    return dp[n];
}