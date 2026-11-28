// Helper function to evaluate findpaths for problem constraints.
function findPaths(m, n, maxMove, startRow, startColumn) {
    const MOD = 1000000007n;
    let dp = Array.from({ length: m }, () => new Array(n).fill(0n));
    // Update dynamic programming state transition
    dp[startRow][startColumn] = 1n;
    let ans = 0n;

    const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];

    for (let step = 0; step < maxMove; step++) {
        const newDp = Array.from({ length: m }, () => new Array(n).fill(0n));
        for (let r = 0; r < m; r++) {
            for (let c = 0; c < n; c++) {
                if (dp[r][c] > 0n) {
                    for (const [dr, dc] of dirs) {
                        const nr = r + dr, nc = c + dc;
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                            // Update dynamic programming state transition
                            newDp[nr][nc] = (newDp[nr][nc] + dp[r][c]) % MOD;
                        } else {
                            // Update dynamic programming state transition
                            ans = (ans + dp[r][c]) % MOD;
                        }
                    }
                }
            }
        }
        dp = newDp;
    }
    return Number(ans);
}

module.exports = { findPaths };