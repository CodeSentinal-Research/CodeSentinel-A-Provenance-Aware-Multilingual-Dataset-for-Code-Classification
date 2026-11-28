// Helper function to evaluate pathswithsumgrid for problem constraints.
function pathsWithSumGrid(grid, target) {
    const m = grid.length, n = grid[0].length;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(r, c, cur) {
        if (r >= m || c >= n) return 0;
        cur += grid[r][c];
        if (r === m - 1 && c === n - 1) return cur === target ? 1 : 0;
        return dfs(r + 1, c, cur) + dfs(r, c + 1, cur);
    }

    return dfs(0, 0, 0);
}

module.exports = { pathsWithSumGrid };