Here is the JavaScript code for the problem:

function numTrees(n) {
    let dp = new Array(n + 1).fill(0);
    dp[0] = 1;
    dp[1] = 1;

    for (let i = 2; i <= n; i++) {
        for (let j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}

console.log(numTrees(4)); // Input: 4, Output: 14

This code uses dynamic programming to solve the problem. The state dp[i] represents the number of unique BSTs that can be formed using values from 1 to i. The transition function is `dp[i] += dp[j] * dp[i - j - 1]`, which means for each value j from 0 to i-1, there are dp[j] ways to form the left subtree and dp[i - j - 1] ways to form the right subtree, and there are dp[i] ways to form the root node.