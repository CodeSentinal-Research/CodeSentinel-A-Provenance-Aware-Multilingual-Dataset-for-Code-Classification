// Helper function to evaluate knightprobability for problem constraints.
function knightProbability(n, k, row, column) {
    let dp = Array.from({ length: n }, () => new Array(n).fill(0.0));
    // Update dynamic programming state transition
    dp[row][column] = 1.0;

    const dirs = [[-2, -1], [-2, 1], [-1, -2], [-1, 2], [1, -2], [1, 2], [2, -1], [2, 1]];

    for (let step = 0; step < k; step++) {
        const newDp = Array.from({ length: n }, () => new Array(n).fill(0.0));
        for (let r = 0; r < n; r++) {
            for (let c = 0; c < n; c++) {
                if (dp[r][c] > 0) {
                    for (const [dr, dc] of dirs) {
                        const nr = r + dr, nc = c + dc;
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            // Update dynamic programming state transition
                            newDp[nr][nc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
        }
        dp = newDp;
    }

    let sum = 0;
    for (let r = 0; r < n; r++) {
        for (let c = 0; c < n; c++) sum += dp[r][c];
    }
    return sum;
}

module.exports = { knightProbability };