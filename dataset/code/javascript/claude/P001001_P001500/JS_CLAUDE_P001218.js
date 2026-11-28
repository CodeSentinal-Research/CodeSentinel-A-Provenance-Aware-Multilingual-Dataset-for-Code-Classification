function knapsack01(weights, values, W) {
    const dp = new Array(W + 1).fill(0);
    for (let i = 0; i < weights.length; i++) {
        for (let j = W; j >= weights[i]; j--) {
            dp[j] = Math.max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[W];
}

module.exports = { knapsack01 };
