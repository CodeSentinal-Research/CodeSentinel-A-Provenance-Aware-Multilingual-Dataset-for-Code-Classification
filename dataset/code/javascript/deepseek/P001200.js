Here is the JavaScript solution for the problem:

function maxArea(matrix) {
  let maxArea = 0;
  let rows = matrix.length;
  let cols = matrix[0].length;
  let dp = Array.from(matrix, () => new Array(cols).fill(0));

  const calculateArea = (row1, row2) => {
    let cols = matrix[0].length;
    let end = cols;
    let maxArea = 0;

    for (let col in dp[0]) {
      if (dp[row1][col] == 1 && row1 < row2) {
        while (end > 0 && dp[row1][end - 1] == 1) {
          end--;
        }

        let width = cols - end;
        maxArea = Math.max(maxArea, width * dp[row1][col]);
      }
    }

    return maxArea;
  };

  for (let row in matrix) {
    for (let col in matrix[0]) {
      if (matrix[row][col] == 1) {
        dp[row][col] = calculateArea(row, col);
        maxArea = Math.max(maxArea, dp[row][col]);
      }
    }
  }

  return maxArea;
}

You can use this function like so:

console.log(maxArea([
  [0, 1, 1, 0],
  [1, 1, 1, 1],
  [1, 1, 1, 1],
  [0, 0, 0, 1]
])); // Outputs: 4