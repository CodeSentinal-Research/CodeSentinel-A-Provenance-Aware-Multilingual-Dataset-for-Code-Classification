const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const m = parseInt(tokens[0], 10), n = parseInt(tokens[1], 10);
        let idx = 2;
        const grid = [];
        const q = [];
        let fresh = 0;
        for (let r = 0; r < m; r++) {
            const row = [];
            for (let c = 0; c < n; c++) {
                const val = Number(tokens[idx++]);
                row.push(val);
                if (val === 2) q.push([r, c, 0]);
                else if (val === 1) fresh++;
            }
            grid.push(row);
        }
        let mins = 0;
        const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
        while (q.length > 0) {
            const [r, c, d] = q.shift();
            mins = Math.max(mins, d);
            for (const [dr, dc] of dirs) {
                const nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] === 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push([nr, nc, d + 1]);
                }
            }
        }
        console.log(fresh === 0 ? mins : -1);
    }
}
main();