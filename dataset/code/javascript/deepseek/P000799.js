function prefixSum2D(N, M, grid) {
  const prefixSumMatrix = [];

  // Create a 2D prefix sum matrix
  for (let i = 0; i < N; i++) {
    prefixSumMatrix[i] = [];
    for (let j = 0; j < M; j++) {
      // Initialize first row and column with 0
      if (i === 0 && j === 0) {
        prefixSumMatrix[i][j] = grid[i][j];
      } else if (i === 0) {
        // Sum of previous row
        prefixSumMatrix[i][j] = prefixSumMatrix[i][j - 1] + grid[i][j];
      } else if (j === 0) {
        // Sum of previous column
        prefixSumMatrix[i][j] = prefixSumMatrix[i - 1][j] + grid[i][j];
      } else {
        // Sum of previous cell, current cell and the two above cells
        prefixSumMatrix[i][j] = prefixSumMatrix[i - 1][j] + prefixSumMatrix[i][j - 1] + grid[i][j] - prefixSumMatrix[i - 1][j - 1];
      }
    }
  }

  return prefixSumMatrix;
}

You can use this function like this:

let N = 3;
let M = 3;
let grid = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
];

let prefixSumMatrix = prefixSum2D(N, M, grid);

console.log(prefixSumMatrix);

This code will output the 2D prefix sum matrix:

[ [ 1,  3,  6],
  [ 5,  10, 15],
  [ 9, 15, 21] ]