Here is the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let dimensions = [];

rl.on('line', (line) => {
  dimensions = line.split(' ').map(Number);
  const [R, C] = dimensions;
  if (R === 0 || C === 0) {
    return rl.close();
  }
  const grid = [];
  for (let i = 0; i < R; i++) {
    grid.push(rl.readline().split(' ').map(Number));
  }
  const paths = countPaths(grid, R, C);
  console.log(paths);
});

function countPaths(grid, R, C) {
  const dp = Array.from({ length: R }, () => Array(C).fill(0));
  dp[0][0] = 1;
  for (let i = 0; i < R; i++) {
    for (let j = 0; j < C; j++) {
      if (grid[i][j] === 1) continue;
      if (i > 0) dp[i][j] += dp[i-1][j];
      if (j > 0) dp[i][j] += dp[i][j-1];
    }
  }
  return dp[R-1][C-1];
}

This code reads the input from the console, creates a 2D array based on the input dimensions, and then counts the number of unique paths using a dynamic programming approach. The countPaths function iterates over the grid, and for each cell, it checks if the cell is an obstacle or not. If it's not an obstacle, it adds the count of paths from the previous cell in the same row and column to the current cell. If it is an obstacle, it simply ignores this cell. The final count is returned in the bottom-right corner of the grid.