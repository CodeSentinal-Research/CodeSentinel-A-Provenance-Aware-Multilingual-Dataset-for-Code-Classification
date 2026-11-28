// P001224 - Count Ways to Tile a 2×N Board
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const MOD = 1000000007n;
    // Ans is C(n + k - 1, 2 * k)
    const N = BigInt(n + k - 1);
    const K = BigInt(2 * k);
    let num = 1n, den = 1n;
    for (let i = 0n; i < K; i++) {
        num = (num * (N - i)) % MOD;
        den = (den * (i + 1n)) % MOD;
    }
    function power(a, b) {
        let res = 1n;
        a %= MOD;
        while (b > 0n) {
            if (b % 2n === 1n) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b /= 2n;
        }
        return res;
    }
    const invDen = power(den, MOD - 2n);
    console.log(((num * invDen) % MOD).toString());
}

main();
