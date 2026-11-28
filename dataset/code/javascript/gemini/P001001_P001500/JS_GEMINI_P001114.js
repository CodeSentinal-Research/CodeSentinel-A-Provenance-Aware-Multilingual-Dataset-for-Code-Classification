// Helper function to evaluate orangesrotting for problem constraints.
function orangesRotting(grid) {
    const m = grid.length, n = grid[0].length;
    const q = [];
    let fresh = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 2) q.push([i, j, 0]);
            else if (grid[i][j] === 1) fresh++;
        }
    }
    let minutes = 0;
    const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    while (q.length > 0) {
        const [r, c, d] = q.shift();
        minutes = Math.max(minutes, d);
        for (const [dr, dc] of dirs) {
            const nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] === 1) {
                grid[nr][nc] = 2;
                fresh--;
                q.push([nr, nc, d + 1]);
            }
        }
    }
    return fresh === 0 ? minutes : -1;
}

module.exports = { orangesRotting };