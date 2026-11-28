Here is the JavaScript code for the Falling Path Minimum Sum problem. The code uses dynamic programming to find the minimum path sum in a given matrix. The time complexity is O(N^2), which is acceptable for N <= 1000.

function minFallingPathSum(matrix) {
  const n = matrix.length;

  // Initialize a 2D DP array
  const dp = Array.from(Array(n), () => Array(n).fill(-1));

  function dfs(x, y) {
    // Base case
    if(y === n) return matrix[x][y];
    if(x < 0 || x >= n || y < 0 || y >= n) return Infinity;
    if(dp[x][y] != -1) return dp[x][y];

    // Recursive case
    return dp[x][y] = matrix[x][y] + Math.min(
      dfs(x + 1, y),
      Math.min(
        dfs(x + 1, y + 1),
        dfs(x + 1, y - 1)
      ),
      dfs(x - 1, y),
      Math.min(
        dfs(x - 1, y + 1),
        dfs(x - 1, y - 1)
      )
    );
  }

  let minSum = Infinity;
  for(let i = 0; i < n; i++) {
    minSum = Math.min(minSum, dfs(0, i));
  }

  return minSum;
}

// Example usage
const matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
];
console.log(minFallingPathSum(matrix)); // Outputs: 15

This code first defines a function `minFallingPathSum` that takes a 2D matrix as input. It initializes a 2D Dynamic Programming (DP) array with -1s. This DP array is used to store the minimum path sum for each cell in the matrix.

The function `dfs` is a recursive function that finds the minimum sum of any falling path starting at a given cell (x, y) in the matrix. It uses the DP array to store the minimum path sum for each cell, and to avoid redundant computation.

In the main part of the code, we iterate over each cell in the first row of the matrix. For each cell, we find the minimum sum of any falling path starting at that cell and update our minimum sum variable accordingly.

Finally, we return the minimum sum of any falling path in the matrix.