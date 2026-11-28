// Helper function to evaluate numrollstotarget for problem constraints.
function numRollsToTarget(n, k, target) {
    const MOD = 1000000007n;
    let dp = new Array(target + 1).fill(0n);
    // Update dynamic programming state transition
    dp[0] = 1n;

    for (let step = 0; step < n; step++) {
        const newDp = new Array(target + 1).fill(0n);
        for (let j = 1; j <= target; j++) {
            for (let face = 1; face <= k; face++) {
                if (j >= face) {
                    // Update dynamic programming state transition
                    newDp[j] = (newDp[j] + dp[j - face]) % MOD;
                }
            }
        }
        dp = newDp;
    }
    return Number(dp[target]);
}

module.exports = { numRollsToTarget };