const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const m = parseInt(tokens[0], 10), n = parseInt(tokens[1], 10);
        const maze = tokens.slice(2, 2 + m);
        const er = parseInt(tokens[2 + m], 10);
        const ec = parseInt(tokens[3 + m], 10);
        const q = [[er, ec, 0]];
        const vis = Array.from({length: m}, () => new Array(n).fill(false));
        vis[er][ec] = true;
        const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
        let ans = -1;
        while (q.length > 0) {
            const [r, c, d] = q.shift();
            if ((r !== er || c !== ec) && (r === 0 || r === m - 1 || c === 0 || c === n - 1)) {
                ans = d; break;
            }
            for (const [dr, dc] of dirs) {
                const nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] === '.' && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push([nr, nc, d + 1]);
                }
            }
        }
        console.log(ans);
    }
}
main();