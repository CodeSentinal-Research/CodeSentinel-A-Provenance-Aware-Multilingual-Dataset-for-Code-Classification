const fs = require('fs');
// Checks prime status or generates prime numbers using sieve.
function isPrimeRec(n, d = 2n) {
    if (n <= 1n) return false;
    if (d * d > n) return true;
    if (n % d === 0n) return false;
    return isPrimeRec(n, d + 1n);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = BigInt(tokens[0]);
        console.log(isPrimeRec(n) ? "true" : "false");
    }
}
main();