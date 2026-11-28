const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const m = parseInt(tokens[0], 10), n = parseInt(tokens[1], 10);
        let idx = 2;
        const forest = [], trees = [];
        for (let r = 0; r < m; r++) {
            const row = [];
            for (let c = 0; c < n; c++) {
                const val = Number(tokens[idx++]);
                row.push(val);
                if (val > 1) trees.push([val, r, c]);
            }
            forest.push(row);
        }
        trees.sort((a, b) => a[0] - b[0]);
        const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
        function bfs(sr, sc, tr, tc) {
            if (sr === tr && sc === tc) return 0;
            const q = [[sr, sc, 0]];
            const vis = Array.from({length: m}, () => new Array(n).fill(false));
            vis[sr][sc] = true;
            while (q.length > 0) {
                const [r, c, d] = q.shift();
                for (const [dr, dc] of dirs) {
                    const nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && forest[nr][nc] !== 0 && !vis[nr][nc]) {
                        if (nr === tr && nc === tc) return d + 1;
                        vis[nr][nc] = true;
                        q.push([nr, nc, d + 1]);
                    }
                }
            }
            return -1;
        }
        let total = 0, curR = 0, curC = 0;
        for (const [val, tr, tc] of trees) {
            const steps = bfs(curR, curC, tr, tc);
            if (steps === -1) { console.log(-1); return; }
            total += steps;
            curR = tr; curC = tc;
        }
        console.log(total);
    }
}
main();