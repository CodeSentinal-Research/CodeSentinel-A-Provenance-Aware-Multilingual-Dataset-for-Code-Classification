const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter R and C (separated by space): ', (R, C) => {
  const grid = [];
  rl.setPrompt('Enter grid values: ');

  for (let i = 0; i < R; i++) {
    grid[i] = rl.readLine('').split(' ').map(Number);
  }

  const minPathSum = (R, C, grid) => {
    const dp = new Array(R).fill(0).map(() => new Array(C).fill(0));

    dp[0][0] = grid[0][0];

    for (let i = 1; i < R; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (let j = 1; j < C; j++) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (let i = 1; i < R; i++) {
      for (let j = 1; j < C; j++) {
        dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[R - 1][C - 1];
  }

  console.log(minPathSum(R, C, grid));

  rl.close();
});