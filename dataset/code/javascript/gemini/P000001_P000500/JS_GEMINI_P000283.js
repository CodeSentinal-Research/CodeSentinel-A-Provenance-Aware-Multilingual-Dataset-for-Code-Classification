function lcs(x, y, s1, s2) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: x + 1 }, () => new Array(y + 1).fill(0));
    for (let i = 1; i <= x; i++) {
        for (let j = 1; j <= y; j++) {
            if (s1[i - 1] === s2[j - 1]) {
                // Update dynamic programming state transition
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Update dynamic programming state transition
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[x][y];
}

module.exports = { lcs };