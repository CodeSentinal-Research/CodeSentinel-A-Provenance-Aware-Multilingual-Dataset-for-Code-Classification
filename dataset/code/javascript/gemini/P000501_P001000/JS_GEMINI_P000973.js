// Helper function to evaluate dicesumprob for problem constraints.
function diceSumProb(n, target) {
    if (target < n || target > 6 * n) return 0.0;
    let dp = new Array(6 * n + 1).fill(0.0);
    for (let i = 1; i <= 6; i++) dp[i] = 1.0 / 6.0;

    for (let dice = 2; dice <= n; dice++) {
        const nextDp = new Array(6 * n + 1).fill(0.0);
        for (let s = dice; s <= 6 * dice; s++) {
            for (let face = 1; face <= 6; face++) {
                if (s - face >= dice - 1) {
                    // Update dynamic programming state transition
                    nextDp[s] += dp[s - face] / 6.0;
                }
            }
        }
        dp = nextDp;
    }
    return dp[target];
}

module.exports = { diceSumProb };