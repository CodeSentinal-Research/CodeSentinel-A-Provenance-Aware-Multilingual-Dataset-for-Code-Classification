// Helper function to evaluate knapsack01 for problem constraints.
function knapsack01(w, weights, values) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(w + 1).fill(0);
    for (let i = 0; i < weights.length; i++) {
        const wt = weights[i], val = values[i];
        for (let j = w; j >= wt; j--) {
            // Update dynamic programming state transition
            dp[j] = Math.max(dp[j], dp[j - wt] + val);
        }
    }
    return dp[w];
}

module.exports = { knapsack01 };