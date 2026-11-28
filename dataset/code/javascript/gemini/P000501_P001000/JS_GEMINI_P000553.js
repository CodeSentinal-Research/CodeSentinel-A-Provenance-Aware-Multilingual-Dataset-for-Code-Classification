const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        let idx = 1;
        const board = [];
        for (let i = 0; i < n; i++) {
            board.push(tokens.slice(idx, idx + n).map(Number));
            idx += n;
        }
        const arr = new Array(n * n + 1).fill(-1);
        let cur = 1;
        for (let r = n - 1; r >= 0; r--) {
            if ((n - 1 - r) % 2 === 0) {
                for (let c = 0; c < n; c++) arr[cur++] = board[r][c];
            } else {
                for (let c = n - 1; c >= 0; c--) arr[cur++] = board[r][c];
            }
        }
        const q = [[1, 0]];
        const vis = new Set([1]);
        let ans = -1;
        while (q.length > 0) {
            const [pos, moves] = q.shift();
            if (pos === n * n) { ans = moves; break; }
            for (let step = 1; step <= 6; step++) {
                const nxt = pos + step;
                if (nxt <= n * n) {
                    const dest = arr[nxt] !== -1 ? arr[nxt] : nxt;
                    if (!vis.has(dest)) {
                        vis.add(dest);
                        q.push([dest, moves + 1]);
                    }
                }
            }
        }
        console.log(ans);
    }
}
main();