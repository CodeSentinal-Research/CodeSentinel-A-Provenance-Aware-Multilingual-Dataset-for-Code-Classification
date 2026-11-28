// Helper function to evaluate findpaths for problem constraints.
function findPaths(maze) {
    const n = maze.length;
    if (maze[0][0] === 0 || maze[n - 1][n - 1] === 0) return [];

    const visited = Array.from({ length: n }, () => new Array(n).fill(false));
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(r, c, path) {
        if (r === n - 1 && c === n - 1) {
            res.push(path);
            return;
        }

        visited[r][c] = true;
        const moves = [[1, 0, 'D'], [0, -1, 'L'], [0, 1, 'R'], [-1, 0, 'U']];
        for (const [dr, dc, d] of moves) {
            const nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && maze[nr][nc] === 1) {
                backtrack(nr, nc, path + d);
            }
        }
        visited[r][c] = false;
    }

    backtrack(0, 0, "");
    return res;
}

module.exports = { findPaths };