// Helper function to evaluate cancross for problem constraints.
function canCross(stones) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Map();
    for (const s of stones) dp.set(s, new Set());
    dp.get(0).add(0);

    for (const s of stones) {
        for (const k of dp.get(s)) {
            for (const step of [k - 1, k, k + 1]) {
                if (step > 0 && dp.has(s + step)) {
                    dp.get(s + step).add(step);
                }
            }
        }
    }
    return dp.get(stones[stones.length - 1]).size > 0;
}

module.exports = { canCross };