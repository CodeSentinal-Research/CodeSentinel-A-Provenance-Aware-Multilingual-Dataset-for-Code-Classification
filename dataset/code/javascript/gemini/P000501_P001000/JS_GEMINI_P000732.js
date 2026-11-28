const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const grid = [];
        let idx = 1;
        for (let i = 0; i < n; i++) {
            grid.push(tokens.slice(idx, idx + n).map(Number));
            idx += n;
        }
        if (grid[0][0] === 0 || grid[n - 1][n - 1] === 0) return;
        const res = [];
        const vis = Array.from({length: n}, () => Array(n).fill(false));
        const moves = [['D', 1, 0], ['L', 0, -1], ['R', 0, 1], ['U', -1, 0]];
        function backtrack(r, c, path) {
            if (r === n - 1 && c === n - 1) {
                res.push(path);
                return;
            }
            vis[r][c] = true;
            for (const [m, dr, dc] of moves) {
                const nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] === 1 && !vis[nr][nc]) {
                    backtrack(nr, nc, path + m);
                }
            }
            vis[r][c] = false;
        }
        backtrack(0, 0, "");
        res.sort();
        for (const p of res) console.log(p);
    }
}
main();