const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(BigInt);
        const pref = new Array(n + 1).fill(0n);
        for (let i = 0; i < n; i++) pref[i + 1] = pref[i] + nums[i];
        const q = parseInt(tokens[1 + n], 10);
        let idx = 2 + n;
        for (let i = 0; i < q; i++) {
            const l = parseInt(tokens[idx], 10), r = parseInt(tokens[idx + 1], 10);
            console.log((pref[r + 1] - pref[l]).toString());
            idx += 2;
        }
    }
}
main();