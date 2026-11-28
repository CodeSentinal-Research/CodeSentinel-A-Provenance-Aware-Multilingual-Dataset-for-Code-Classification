const fs = require('fs');
// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function gcdRec(a, b) {
    if (b === 0n) return a;
    return gcdRec(b, a % b);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const a = BigInt(tokens[0]), b = BigInt(tokens[1]);
        console.log(gcdRec(a, b).toString());
    }
}
main();