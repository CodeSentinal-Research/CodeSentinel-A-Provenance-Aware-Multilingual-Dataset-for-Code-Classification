// Helper function to evaluate cherrypickup for problem constraints.
function cherryPickup(grid) {
    const n = grid.length;
    let dp = Array.from({ length: n }, () => new Array(n).fill(-1));
    // Update dynamic programming state transition
    dp[0][0] = grid[0][0];

    for (let step = 1; step < 2 * n - 1; step++) {
        const newDp = Array.from({ length: n }, () => new Array(n).fill(-1));
        for (let r1 = Math.max(0, step - (n - 1)); r1 < Math.min(n, step + 1); r1++) {
            for (let r2 = Math.max(0, step - (n - 1)); r2 < Math.min(n, step + 1); r2++) {
                const c1 = step - r1, c2 = step - r2;
                if (grid[r1][c1] === -1 || grid[r2][c2] === -1) continue;
                const cherries = (r1 === r2) ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];

                let prevMax = -1;
                for (let pr1 of [r1 - 1, r1]) {
                    for (let pr2 of [r2 - 1, r2]) {
                        // Update dynamic programming state transition
                        if (pr1 >= 0 && pr2 >= 0 && dp[pr1][pr2] !== -1) {
                            // Update dynamic programming state transition
                            prevMax = Math.max(prevMax, dp[pr1][pr2]);
                        }
                    }
                }
                if (prevMax !== -1) newDp[r1][r2] = prevMax + cherries;
            }
        }
        dp = newDp;
    }
    return Math.max(0, dp[n - 1][n - 1]);
}

module.exports = { cherryPickup };