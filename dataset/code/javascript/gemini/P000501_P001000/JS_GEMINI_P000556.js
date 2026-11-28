const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const m = parseInt(tokens[0], 10), n = parseInt(tokens[1], 10);
        let idx = 2;
        const grid = [];
        for (let i = 0; i < m; i++) {
            grid.push(tokens.slice(idx, idx + n).map(Number));
            idx += n;
        }
        if (m === 1 && n === 1) { console.log(1); return; }
        const dist = Array.from({length: m}, () => new Array(n).fill(Infinity));
        dist[0][0] = 1;
        const maxR = new Array(m).fill(0), maxC = new Array(n).fill(0);
        const q = [[0, 0]];
        while (q.length > 0) {
            const [r, c] = q.shift();
            const d = dist[r][c], k = grid[r][c];
            const startC = Math.max(c + 1, maxR[r] + 1);
            const endC = Math.min(c + k, n - 1);
            for (let nc = startC; nc <= endC; nc++) {
                if (dist[r][nc] === Infinity) {
                    dist[r][nc] = d + 1;
                    if (r === m - 1 && nc === n - 1) { console.log(d + 1); return; }
                    q.push([r, nc]);
                }
            }
            maxR[r] = Math.max(maxR[r], endC);
            const startR = Math.max(r + 1, maxC[c] + 1);
            const endR = Math.min(r + k, m - 1);
            for (let nr = startR; nr <= endR; nr++) {
                if (dist[nr][c] === Infinity) {
                    dist[nr][c] = d + 1;
                    if (nr === m - 1 && c === n - 1) { console.log(d + 1); return; }
                    q.push([nr, c]);
                }
            }
            maxC[c] = Math.max(maxC[c], endR);
        }
        console.log(dist[m - 1][n - 1] !== Infinity ? dist[m - 1][n - 1] : -1);
    }
}
main();