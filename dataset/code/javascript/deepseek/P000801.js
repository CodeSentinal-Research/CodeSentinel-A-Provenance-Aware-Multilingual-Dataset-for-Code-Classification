Here is the JavaScript code to solve the problem:

function matrixBlockSum(N, M, grid, K) {
  let prefixSum = new Array(N + 1).fill(0).map(() => new Array(M + 1).fill(0));

  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= M; j++) {
      prefixSum[i][j] = grid[i - 1][j - 1] + prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1];
    }
  }

  let result = new Array(N).fill(0).map(() => new Array(M).fill(0));

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      let r1 = Math.max(0, i - K);
      let c1 = Math.max(0, j - K);
      let r2 = Math.min(N - 1, i + K);
      let c2 = Math.min(M - 1, j + K);

      let sum = prefixSum[r2 + 1][c2 + 1] - prefixSum[r2 + 1][c1] - prefixSum[r1][c2 + 1] + prefixSum[r1][c1];

      result[i][j] = sum;
    }
  }

  return result;
}

This code first constructs a 2D prefix sum for the input matrix. It then creates a result matrix and calculates the sum of elements in a certain range (from r1 to r2, from c1 to c2) in the prefix sum matrix. The result is stored in the result matrix.

Please note that the input matrix is 1-indexed, meaning the first row and the first column of the matrix are 1, not 0. Also, the indices for the result matrix are 0-indexed, meaning the first row and the first column of the result matrix are 0, not 1.

You can call the function with the following inputs:

let N = 3, M = 3, K = 2;
let grid = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
let result = matrixBlockSum(N, M, grid, K);
console.log(result);

This will print the result matrix.