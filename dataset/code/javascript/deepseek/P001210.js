let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let lines = [];
rl.on('line', (line) => {
  lines.push(line);
}).on('close', () => {
  solve(lines[0], lines[1].split(' ').map(Number));
});

function solve(n, coins) {
  let dp = new Array(n + 1);
  dp[0] = 0;
  dp[1] = coins[0];
  for (let i = 2; i <= n; i++) {
    dp[i] = Math.max(dp[i - 1], dp[i - 2] + coins[i - 1]);
  }
  console.log(dp[n]);
}
In this code, we use a dynamic programming approach to solve the problem. The `dp` array stores the maximum value we can achieve by considering the first player's turn so far. For each coin, we consider whether to pick the leftmost or rightmost coin, and update the `dp` array accordingly. The maximum value by the first player is the last element in `dp` array.