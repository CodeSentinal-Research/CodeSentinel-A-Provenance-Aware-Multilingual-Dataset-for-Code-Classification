Here is the JavaScript code to solve the problem:

function stoneGameII(piles) {
    let n = piles.length;
    let dp = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));
    let sum = new Array(n + 1).fill(0).slice(1);
    for (let i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + piles[i];
    }
    for (let len = 1; len <= n; len++) {
        for (let i = 1; i + len <= n; i++) {
            let L = i, R = i + len;
            dp[L][R] = sum[R] - sum[L - 1] - dp[L][i - 1] * 2;
            if (R - L > 1) {
                dp[L][R] = Math.max(dp[L][R], sum[R - 1] - sum[L] - dp[i + 1][R - L - 1]);
            }
        }
    }
    return dp[1][n];
}

// Test the function
let piles = [5, 3, 4, 2, 6, 7, 2, 3, 4, 2, 1, 8, 2, 3, 4, 2, 1, 8, 2, 3, 4, 2, 1, 8];
console.log(stoneGameII(piles));

This function uses dynamic programming to solve the problem. The `dp` array stores the maximum stones Alice can obtain with the current turn, and the `sum` array stores the cumulative sum of the stones. For each pile, we calculate the maximum stones Alice can obtain from the current pile and the remaining piles after the current pile. Then we update the `dp` array for the next piles. At the end, we return the maximum stones Alice can obtain.