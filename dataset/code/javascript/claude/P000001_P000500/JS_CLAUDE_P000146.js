function maximalSquare(matrix) {
    if (!matrix.length) return 0;
    const m = matrix.length, n = matrix[0].length;
    const dp = Array.from({length: m}, () => new Array(n).fill(0));
    let side = 0;
    for (let i = 0; i < m; i++)
        for (let j = 0; j < n; j++)
            if (matrix[i][j] === '1' || matrix[i][j] === 1) {
                dp[i][j] = (i === 0 || j === 0) ? 1 :
                    Math.min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                side = Math.max(side, dp[i][j]);
            }
    return side * side;
}
module.exports = { maximalSquare };
