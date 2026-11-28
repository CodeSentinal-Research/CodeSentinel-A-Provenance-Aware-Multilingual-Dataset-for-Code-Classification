const fs = require('fs');
// Calculates modular exponentiation (base^exp % mod) efficiently.
function modPowRec(base, exp, mod) {
    if (exp === 0n) return 1n % mod;
    const half = modPowRec(base, exp / 2n, mod);
    let res = (half * half) % mod;
    if (exp % 2n !== 0n) res = (res * (base % mod)) % mod;
    return res;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const base = BigInt(tokens[0]), exp = BigInt(tokens[1]), mod = BigInt(tokens[2]);
        console.log(modPowRec(base, exp, mod).toString());
    }
}
main();