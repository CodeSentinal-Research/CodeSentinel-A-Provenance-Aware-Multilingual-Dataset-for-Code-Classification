// Helper function to evaluate shortestpathbinarymatrix for problem constraints.
function shortestPathBinaryMatrix(grid) {
    const n = grid.length;
    if (grid[0][0] !== 0 || grid[n - 1][n - 1] !== 0) return -1;

    const q = [[0, 0, 1]];
    grid[0][0] = 1;

    const dirs = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]];
    while (q.length > 0) {
        const [r, c, d] = q.shift();
        if (r === n - 1 && c === n - 1) return d;
        for (const [dr, dc] of dirs) {
            const nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] === 0) {
                grid[nr][nc] = 1;
                q.push([nr, nc, d + 1]);
            }
        }
    }
    return -1;
}

module.exports = { shortestPathBinaryMatrix };