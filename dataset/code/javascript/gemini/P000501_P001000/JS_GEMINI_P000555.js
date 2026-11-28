const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10), p = parseInt(tokens[1], 10), b = parseInt(tokens[2], 10);
        const banned = new Set(tokens.slice(3, 3 + b).map(Number));
        const k = parseInt(tokens[3 + b], 10);
        const res = new Array(n).fill(-1);
        res[p] = 0;
        const unvisited = [new Set(), new Set()];
        for (let i = 0; i < n; i++) {
            if (i !== p && !banned.has(i)) unvisited[i % 2].add(i);
        }
        const q = [p];
        while (q.length > 0) {
            const cur = q.shift();
            const minIdx = Math.max(cur - k + 1, k - 1 - cur);
            const maxIdx = Math.min(cur + k - 1, 2 * n - k - 1 - cur);
            const parity = minIdx % 2;
            const toRemove = [];
            for (const nxt of unvisited[parity]) {
                if (nxt >= minIdx && nxt <= maxIdx) {
                    res[nxt] = res[cur] + 1;
                    q.push(nxt);
                    toRemove.push(nxt);
                }
            }
            for (const x of toRemove) unvisited[parity].delete(x);
        }
        console.log(res.join(' '));
    }
}
main();