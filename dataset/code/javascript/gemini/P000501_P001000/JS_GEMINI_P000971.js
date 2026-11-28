const MOD = 1000000007n;

// Helper function to evaluate evallinearrecurrence for problem constraints.
function evalLinearRecurrence(coeffs, init, n) {
    const k = coeffs.length;
    if (n < k) return init[n];
    // dp table storing optimal subproblem solutions
    const dp = init.map(BigInt);
    const c = coeffs.map(BigInt);
    for (let i = k; i <= n; i++) {
        let val = 0n;
        for (let j = 0; j < k; j++) {
            // Update dynamic programming state transition
            val = (val + c[j] * dp[i - 1 - j]) % MOD;
        }
        dp.push(val);
    }
    return Number(((dp[n] % MOD) + MOD) % MOD);
}

module.exports = { evalLinearRecurrence };