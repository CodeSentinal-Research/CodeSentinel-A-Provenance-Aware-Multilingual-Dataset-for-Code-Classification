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

module.exports = { modPow };