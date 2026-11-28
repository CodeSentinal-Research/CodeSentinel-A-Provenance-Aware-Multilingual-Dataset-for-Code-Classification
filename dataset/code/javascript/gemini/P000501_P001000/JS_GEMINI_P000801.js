const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10), m = parseInt(tokens[1], 10);
        const pref = Array.from({length: n + 1}, () => Array(m + 1).fill(0n));
        let idx = 2;
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                const val = BigInt(tokens[idx++]);
                pref[i + 1][j + 1] = val + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }
        const k = parseInt(tokens[idx++], 10);
        for (let i = 0; i < n; i++) {
            const r1 = Math.max(0, i - k), r2 = Math.min(n - 1, i + k);
            const row = [];
            for (let j = 0; j < m; j++) {
                const c1 = Math.max(0, j - k), c2 = Math.min(m - 1, j + k);
                const ans = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
                row.push(ans);
            }
            console.log(row.join(' '));
        }
    }
}
main();