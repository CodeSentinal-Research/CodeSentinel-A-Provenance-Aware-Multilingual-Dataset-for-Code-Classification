const fs = require('fs');
// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function gcd(a, b) { return b === 0 ? a : gcd(b, a % b); }
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const res = [];
        for (let i = 0; i < n; i++) {
            res.push(vals[i]);
            if (i + 1 < n) res.push(gcd(vals[i], vals[i + 1]));
        }
        console.log(res.join(' '));
    }
}
main();