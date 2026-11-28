const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        let idx = 1;
        const grid = [];
        for (let i = 0; i < n; i++) {
            grid.push(tokens.slice(idx, idx + n).map(Number));
            idx += n;
        }
        const q = [[0, 0, 0, 0]];
        const vis = Array.from({length: n}, () => Array.from({length: n}, () => [false, false]));
        vis[0][0][0] = true;
        let ans = -1;
        while (q.length > 0) {
            const [r, c, s, d] = q.shift();
            if (s === 0 && r === n - 1 && c === n - 2) { ans = d; break; }
            if (s === 0) {
                if (c + 2 < n && grid[r][c + 2] === 0 && !vis[r][c + 1][0]) {
                    vis[r][c + 1][0] = true; q.push([r, c + 1, 0, d + 1]);
                }
                if (r + 1 < n && grid[r + 1][c] === 0 && grid[r + 1][c + 1] === 0 && !vis[r + 1][c][0]) {
                    vis[r + 1][c][0] = true; q.push([r + 1, c, 0, d + 1]);
                }
                if (r + 1 < n && grid[r + 1][c] === 0 && grid[r + 1][c + 1] === 0 && !vis[r][c][1]) {
                    vis[r][c][1] = true; q.push([r, c, 1, d + 1]);
                }
            } else {
                if (c + 1 < n && grid[r][c + 1] === 0 && grid[r + 1][c + 1] === 0 && !vis[r][c + 1][1]) {
                    vis[r][c + 1][1] = true; q.push([r, c + 1, 1, d + 1]);
                }
                if (r + 2 < n && grid[r + 2][c] === 0 && !vis[r + 1][c][1]) {
                    vis[r + 1][c][1] = true; q.push([r + 1, c, 1, d + 1]);
                }
                if (c + 1 < n && grid[r][c + 1] === 0 && grid[r + 1][c + 1] === 0 && !vis[r][c][0]) {
                    vis[r][c][0] = true; q.push([r, c, 0, d + 1]);
                }
            }
        }
        console.log(ans);
    }
}
main();