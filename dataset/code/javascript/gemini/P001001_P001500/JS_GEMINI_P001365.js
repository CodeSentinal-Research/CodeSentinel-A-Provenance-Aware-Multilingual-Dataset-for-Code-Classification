// Helper function to evaluate getmaximumgold for problem constraints.
function getMaximumGold(grid) {
    const m = grid.length, n = grid[0].length;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(r, c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] === 0) return 0;
        const gold = grid[r][c];
        grid[r][c] = 0;

        const maxSub = Math.max(
            dfs(r + 1, c),
            dfs(r - 1, c),
            dfs(r, c + 1),
            dfs(r, c - 1)
        );

        grid[r][c] = gold;
        return gold + maxSub;
    }

    let maxGold = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] > 0) {
                maxGold = Math.max(maxGold, dfs(i, j));
            }
        }
    }
    return maxGold;
}

module.exports = { getMaximumGold };