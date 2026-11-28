function minCapability(n, nums, k) {
    if (k >= n) {
        return Math.max(...nums);
    }

    // Initialize dp[][]
    let dp = Array.from(Array(n + 1), () => Array(k + 1).fill(-Infinity));

    dp[0][0] = 0;

    // Populate dp[][]
    for (let i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0];
        for (let j = 1; j <= k; j++) {
            dp[i][j] = Math.max(
                dp[i - 1][j],
                dp[i - 1][j - 1] + nums[i - 1]
            );
        }
    }

    return dp[n][k];
}

This JavaScript function uses a dynamic programming approach to solve the House Robber IV problem. The function takes three parameters: the number of houses, an array of house numbers, and the number of houses to rob.

If the number of houses to rob is greater than or equal to the number of houses, it means we can rob all the houses, so we can return the maximum house number.

The function initializes a two-dimensional array dp[][] with a size of (n + 1)x(k + 1) filled with negative infinity. The first row and first column of dp[][] are initialized with 0.

In the next loop, the function iterates over the dp[][] array and fills up the dp[][] array accordingly. For each cell (i, j), the function checks if we rob the i-th house and if it is possible to rob the i-th house with j robbed houses. If it is possible to rob the i-th house, we can choose either to rob it (dp[i - 1][j]) or to skip it (dp[i - 1][j - 1] + nums[i - 1]). We take the maximum of these two choices.

Finally, the function returns the minimum capability from the last cell of the dp[][] array.