Here's the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the length of the rod: ', (N) => {
  rl.question('Enter prices of each length from 1 to N: ', (tillN) => {
    const prices = tillN.split(' ').map(Number);
    console.log(maxCuts(N, prices));
    rl.close();
  });
});

function maxCuts(n, prices) {
  const dp = new Array(n + 1).fill(0);
  const size = prices.length;
  for (let i = 1; i <= n; i++) {
    let max = 0;
    for (let j = 0; j < size; j++) {
      if (i >= prices[j]) {
        max = Math.max(max, dp[i - prices[j]] + 1);
      }
    }
    dp[i] = max;
  }
  return dp[n];
}

This code uses a dynamic programming approach to solve the rod cutting problem. It creates a `dp` array where `dp[i]` represents the maximum revenue we can get with `i` pieces. Then, for each length from 1 to `n`, it tries to cut it into smaller pieces and updates `dp[i]` by taking the maximum of `dp[i]` and `dp[j] + dp[i - j - 1]` (price of each piece) where `j` ranges from 0 to `i - 1`.

It reads the length of the rod and the prices of each length from 1 to N from the input and then prints the maximum obtainable revenue.