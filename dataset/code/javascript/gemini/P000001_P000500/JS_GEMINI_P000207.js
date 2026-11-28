function maxSum(grid) {
    const m = grid.length, n = grid[0].length;
    let maxSum = -Infinity;

    for (let i = 0; i < m - 2; i++) {
        for (let j = 0; j < n - 2; j++) {
            const curSum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2]
                         + grid[i + 1][j + 1]
                         + grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
            if (curSum > maxSum) maxSum = curSum;
        }
    }
    return maxSum;
}

module.exports = { maxSum };