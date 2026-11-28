function longestCommonSubstr(S1, S2, n, m) {
    // dp table storing optimal subproblem solutions
    const dp = Array.from({ length: n + 1 }, () => new Array(m + 1).fill(0));
    let res = 0;

    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= m; j++) {
            if (S1[i - 1] === S2[j - 1]) {
                // Update dynamic programming state transition
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // Update dynamic programming state transition
                if (dp[i][j] > res) res = dp[i][j];
            }
        }
    }
    return res;
}

module.exports = { longestCommonSubstr };