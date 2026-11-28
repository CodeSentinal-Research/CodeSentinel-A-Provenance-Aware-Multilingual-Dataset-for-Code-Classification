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
        const threshold = BigInt(tokens[idx++]);
        let maxLen = 0;
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                while (i + maxLen < n && j + maxLen < m) {
                    const sum = pref[i + maxLen + 1][j + maxLen + 1] - pref[i][j + maxLen + 1] - pref[i + maxLen + 1][j] + pref[i][j];
                    if (sum <= threshold) maxLen++;
                    else break;
                }
            }
        }
        console.log(maxLen);
    }
}
main();