const fs = require('fs');
const MOD = 1000000007n;
// Calculates modular exponentiation (base^exp % mod) efficiently.
function modPow(base, exp, mod) {
    if (exp === 0n) return 1n;
    const half = modPow(base, exp / 2n, mod);
    let res = (half * half) % mod;
    if (exp % 2n !== 0n) res = (res * base) % mod;
    return res;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = BigInt(tokens[0]);
        const evenPos = (n + 1n) / 2n;
        const oddPos = n / 2n;
        const ans = (modPow(5n, evenPos, MOD) * modPow(4n, oddPos, MOD)) % MOD;
        console.log(ans.toString());
    }
}
main();