Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of rows R: ', (R) => {
  rl.question('Enter the number of columns C: ', (C) => {
    const grid = [];
    for (let i = 0; i < R; i++) {
      rl.question(`Enter row ${i + 1} of costs: `, (row) => {
        grid[i] = row.split(' ').map(Number);
        if (i != R - 1) rl.setPrompt(`Enter row ${i + 2} of costs: `);
      });
    }
    console.log(minCost(grid, R, C));
    rl.close();
  });
});

function minCost(grid, R, C) {
  const dp = Array(R + 1).fill(null).map(() => Array(C + 1).fill(Infinity));
  dp[0][0] = 0;
  for (let i = 0; i < R; i++) {
    for (let j = 0; j < C; j++) {
      if (i > 0) dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + grid[i][j]);
      if (j > 0) dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + grid[i][j]);
    }
  }
  return dp[R - 1][C - 1];
}

This code will take the number of rows and columns as input and then read the grid of traversal costs. It uses a dynamic programming approach to calculate the minimum cost to reach the bottom-right corner from the top-left corner by moving only right or down.