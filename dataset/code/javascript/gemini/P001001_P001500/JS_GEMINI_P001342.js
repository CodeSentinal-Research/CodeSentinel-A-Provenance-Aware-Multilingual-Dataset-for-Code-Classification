// Helper function to evaluate countincreasingsubsequences for problem constraints.
function countIncreasingSubsequences(arr, k) {
    const MOD = 1000000007n;
    const n = arr.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: n }, () => new Array(k + 1).fill(0n));

    for (let i = 0; i < n; i++) dp[i][1] = 1n;

    for (let len = 2; len <= k; len++) {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    // Update dynamic programming state transition
                    dp[i][len] = (dp[i][len] + dp[j][len - 1]) % MOD;
                }
            }
        }
    }

    let ans = 0n;
    for (let i = 0; i < n; i++) ans = (ans + dp[i][k]) % MOD;
    return Number(ans);
}

module.exports = { countIncreasingSubsequences };