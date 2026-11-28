// Helper function to evaluate phi for problem constraints.
function phi(n) {
    let res = n;
    let p = 2;
    while (p * p <= n) {
        if (n % p === 0) {
            while (n % p === 0) n = Math.floor(n / p);
            res -= Math.floor(res / p);
        }
        p++;
    }
    if (n > 1) res -= Math.floor(res / n);
    return res;
}

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

// Calculates modular exponentiation (base^exp % mod) efficiently.
function eulerPow(a, b, m) {
    const p = phi(m);
    return modPow(a, b % p, m);
}

module.exports = { eulerPow };