// Calculates modular exponentiation (base^exp % mod) efficiently.
function modPow(base, exp, mod) {
    let res = 1n;
    let b = BigInt(base) % BigInt(mod);
    let e = BigInt(exp);
    let m = BigInt(mod);
    while (e > 0n) {
        // If current bit is set, multiply base into result
        if (e % 2n === 1n) res = (res * b) % m;
        // Square the base for the next bit
        b = (b * b) % m;
        e /= 2n;
    }
    return Number(res);
}

// Helper function to evaluate ncrmod for problem constraints.
function nCrMod(n, r, p) {
    if (r < 0 || r > n) return 0;
    let num = 1, den = 1;
    for (let i = 0; i < r; i++) {
        num = (num * (n - i)) % p;
        den = (den * (i + 1)) % p;
    }
    return (num * modPow(den, p - 2, p)) % p;
}

module.exports = { nCrMod };