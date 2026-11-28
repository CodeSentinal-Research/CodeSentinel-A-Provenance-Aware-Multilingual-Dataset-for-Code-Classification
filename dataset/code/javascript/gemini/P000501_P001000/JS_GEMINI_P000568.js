const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const x = Math.abs(parseInt(tokens[0], 10)), y = Math.abs(parseInt(tokens[1], 10));
        const q = [[0, 0, 0]];
        const vis = new Set(['0,0']);
        const dirs = [[-2, -1], [-2, 1], [-1, -2], [-1, 2], [1, -2], [1, 2], [2, -1], [2, 1]];
        while (q.length > 0) {
            const [r, c, d] = q.shift();
            if (r === x && c === y) { console.log(d); return; }
            for (const [dr, dc] of dirs) {
                const nr = r + dr, nc = c + dc;
                if (nr >= -2 && nr <= x + 2 && nc >= -2 && nc <= y + 2 && !vis.has(`${nr},${nc}`)) {
                    vis.add(`${nr},${nc}`);
                    q.push([nr, nc, d + 1]);
                }
            }
        }
    }
}
main();