// Helper function to evaluate numberofarrays for problem constraints.
function numberOfArrays(s, k) {
    const MOD = 1000000007n;
    const n = s.length;
    // dp table storing optimal subproblem solutions
    const dp = new Array(n + 1).fill(0n);
    // Update dynamic programming state transition
    dp[n] = 1n;

    for (let i = n - 1; i >= 0; i--) {
        if (s[i] === '0') continue;
        let cur = 0n;
        for (let j = i; j < n; j++) {
            cur = cur * 10n + BigInt(s[j]);
            if (cur > BigInt(k)) break;
            // Update dynamic programming state transition
            dp[i] = (dp[i] + dp[j + 1]) % MOD;
        }
    }
    return Number(dp[0]);
}

module.exports = { numberOfArrays };