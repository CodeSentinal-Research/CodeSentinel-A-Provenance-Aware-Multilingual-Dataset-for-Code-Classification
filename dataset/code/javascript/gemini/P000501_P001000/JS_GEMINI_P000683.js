const fs = require('fs');
// Calculates modular exponentiation (base^exp % mod) efficiently.
function powerRec(x, n) {
    if (n === 0) return 1n;
    const half = powerRec(x, Math.floor(n / 2));
    if (n % 2 === 0) return half * half;
    return half * half * BigInt(x);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const x = parseInt(tokens[0], 10), n = parseInt(tokens[1], 10);
        console.log(powerRec(x, n).toString());
    }
}
main();