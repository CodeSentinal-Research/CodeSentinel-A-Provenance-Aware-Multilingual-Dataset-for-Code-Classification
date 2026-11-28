const fs = require('fs');
// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function gcd(a, b) { return b === 0n ? a : gcd(b, a % b); }
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const a = BigInt(input[0]), b = BigInt(input[1]);
        const lcm = (a / gcd(a, b)) * b;
        console.log(lcm.toString());
    }
}
main();