Here is the JavaScript code to solve the problem:

let fs = require('fs');
let input = fs.readFileSync('input.txt', 'utf8');
let [rows, cols] = input.split('\n').map(Number);
let matrix = [];
for (let i = 0; i < rows; i++) {
  matrix[i] = input.split('\n')[i].split('').map(Number);
}

let dp = Array.from(matrix, () => Array(cols).fill(0));

let max = 0;
for (let i = 0; i < rows; i++) {
  for (let j = 0; j < cols; j++) {
    if (matrix[i][j] == 1) {
      if (i > 0 && j > 0) {
        dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
      } else {
        dp[i][j] = 1;
      }
      max = Math.max(max, dp[i][j]);
    }
  }
}

console.log(max * max);

This program reads the input from a file named 'input.txt', splits it into rows and columns, and then creates a dynamic programming table dp. The program then iterates over the matrix, updating the dp table based on the smallest side of the current submatrix. The size of the largest square is then calculated as the product of the maximum size of a square that can be formed.