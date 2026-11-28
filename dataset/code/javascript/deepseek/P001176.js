let N;
N = parseInt(readline());
let matrix = [];
for (let i = 0; i < N; i++) {
    matrix[i] = readline().split(' ').map(Number);
}

let dp = Array.from({ length: N + 2 }, () => 0);
let res = -Infinity;

for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
        res = Math.max(res, dp[j] + dp[j + 1] + dp[j + 2] + matrix[i][j]);
        dp[j] = Math.max(dp[j], dp[j + 1], dp[j + 2] + matrix[i][j]);
        dp[j + 2] = Math.max(dp[j + 2], dp[j] + matrix[i][j]);
    }
    dp[N] = dp[N + 1] = 0;
    dp[N + 1] = Math.max(dp[N + 1], dp[N] + matrix[i][N]);
}

print(res);

In this code, we first read the size of the matrix from the first line. Then we read the matrix values. We create three arrays dp and result to store the maximum sum of falling path at each position. We initialize the result as negative infinity.

Then, for each row in the matrix, we calculate the maximum sum of falling path. We update the dp array for each position as follows:

- If the current cell's value is greater than the maximum sum so far, then the maximum sum is the current cell's value plus the maximum sum of the cell above and two cells to the left.
- Otherwise, we take the maximum sum of the cell above and two cells to the left.
- If the current cell's value plus the maximum sum of the cell above and two cells to the left is greater than the maximum sum so far, then the maximum sum is the current cell's value plus the maximum sum of the cell above and two cells to the left.
- If the current cell's value plus the maximum sum of the cell above and one cell to the left is greater than the maximum sum so far, then the maximum sum is the current cell's value plus the maximum sum of the cell above and one cell to the left.
- Otherwise, we take the maximum sum of the cell above and one cell to the left.

Finally, we print the result.