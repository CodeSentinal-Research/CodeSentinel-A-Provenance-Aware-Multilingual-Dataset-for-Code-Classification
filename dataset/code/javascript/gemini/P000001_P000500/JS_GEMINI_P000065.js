const fs = require('fs');
// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function gcd(a, b) { return b === 0n ? a : gcd(b, a % b); }
// Computes the Least Common Multiple (LCM).
function lcm(a, b) { return (a / gcd(a, b)) * b; }
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 3) {
        const a = BigInt(input[0]), b = BigInt(input[1]), c = BigInt(input[2]);
        console.log(lcm(lcm(a, b), c).toString());
    }
}
main();