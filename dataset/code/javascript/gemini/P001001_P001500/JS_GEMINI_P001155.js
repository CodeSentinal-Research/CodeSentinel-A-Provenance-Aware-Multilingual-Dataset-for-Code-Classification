// Helper function to evaluate maxcoins for problem constraints.
function maxCoins(nums) {
    const A = [1, ...nums.filter(x => x > 0), 1];
    const n = A.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: n }, () => new Array(n).fill(0));

    for (let len = 2; len < n; len++) {
        for (let left = 0; left < n - len; left++) {
            const right = left + len;
            for (let i = left + 1; i < right; i++) {
                // Update dynamic programming state transition
                const coins = dp[left][i] + dp[i][right] + A[left] * A[i] * A[right];
                // Update dynamic programming state transition
                if (coins > dp[left][right]) dp[left][right] = coins;
            }
        }
    }
    return dp[0][n - 1];
}

module.exports = { maxCoins };