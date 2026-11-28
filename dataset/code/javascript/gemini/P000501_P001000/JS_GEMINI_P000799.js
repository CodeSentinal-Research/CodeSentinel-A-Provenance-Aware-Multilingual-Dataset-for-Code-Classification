const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10), m = parseInt(tokens[1], 10);
        const pref = Array.from({length: n}, () => Array(m).fill(0n));
        let idx = 2;
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                pref[i][j] = BigInt(tokens[idx++]);
                if (i > 0) pref[i][j] += pref[i - 1][j];
                if (j > 0) pref[i][j] += pref[i][j - 1];
                if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
            }
        }
        for (let i = 0; i < n; i++) console.log(pref[i].join(' '));
    }
}
main();