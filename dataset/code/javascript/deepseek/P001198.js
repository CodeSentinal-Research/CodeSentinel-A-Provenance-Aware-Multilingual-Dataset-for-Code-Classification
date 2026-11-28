Here's the code:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputs = [];

rl.on('line', (line) => {
  inputs.push(line.split(' ').map(Number));
});

rl.on('close', () => {
  const R = inputs[0][0];
  const C = inputs[0][1];
  const matrix = inputs.slice(1).map(row => row.map(Number));

  let dp = new Array(R + 1);
  for (let i = 0; i <= R; i++) {
    dp[i] = new Array(C + 1).fill(0);
  }

  let res = 0;

  for (let i = 1; i <= R; i++) {
    for (let j = 1; j <= C; j++) {
      if (matrix[i - 1][j - 1] === 1) {
        dp[i][j] = Math.min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
        res += dp[i][j];
      }
    }
  }

  console.log(res);
});
This code reads input lines and uses Dynamic Programming to count the total number of square submatrices. The `dp[i][j]` represents the side length of the square submatrix that includes the cell (i, j) in the matrix. We iterate over the matrix and update the `dp[i][j]` for each cell. If the cell has a value of 1, we update `dp[i][j]` to the minimum of the sides in its left, top, and top-left cells plus one (the cell itself). At the end of the process, `res` stores the total count of all square submatrices, and we print it out.