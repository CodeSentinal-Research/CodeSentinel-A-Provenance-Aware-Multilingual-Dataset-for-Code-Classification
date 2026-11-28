// Helper function to evaluate uniquepathsiii for problem constraints.
function uniquePathsIII(grid) {
    const m = grid.length, n = grid[0].length;
    let empty = 0, startR = 0, startC = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                startR = i; startC = j;
            } else if (grid[i][j] === 0) {
                empty++;
            }
        }
    }

    // Helper function to evaluate dfs for problem constraints.
    function dfs(r, c, count) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] < 0) return 0;
        if (grid[r][c] === 2) return count === empty + 1 ? 1 : 0;

        const temp = grid[r][c];
        grid[r][c] = -2;

        const paths = dfs(r + 1, c, count + 1) +
                      dfs(r - 1, c, count + 1) +
                      dfs(r, c + 1, count + 1) +
                      dfs(r, c - 1, count + 1);

        grid[r][c] = temp;
        return paths;
    }

    return dfs(startR, startC, 0);
}

module.exports = { uniquePathsIII };