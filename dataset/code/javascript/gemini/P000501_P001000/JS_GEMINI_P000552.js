const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const m = parseInt(tokens[0], 10), n = parseInt(tokens[1], 10);
        let idx = 2;
        const grid = [], q = [];
        for (let r = 0; r < m; r++) {
            const row = [];
            for (let c = 0; c < n; c++) {
                const val = Number(tokens[idx++]);
                row.push(val);
                if (val === 0) q.push([r, c, 0]);
            }
            grid.push(row);
        }
        const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
        while (q.length > 0) {
            const [r, c, d] = q.shift();
            for (const [dr, dc] of dirs) {
                const nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] === 2147483647) {
                    grid[nr][nc] = d + 1;
                    q.push([nr, nc, d + 1]);
                }
            }
        }
        for (const row of grid) console.log(row.join(' '));
    }
}
main();