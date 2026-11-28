const MOD = 1000000007n;

// Helper function to evaluate matmul for problem constraints.
function matMul(a, b) {
    const n = a.length;
    const res = Array.from({ length: n }, () => new Array(n).fill(0n));
    for (let i = 0; i < n; i++) {
        for (let k = 0; k < n; k++) {
            for (let j = 0; j < n; j++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

// Calculates modular exponentiation (base^exp % mod) efficiently.
function matPow(mat, p) {
    const n = mat.length;
    let res = Array.from({ length: n }, (_, i) =>
        Array.from({ length: n }, (_, j) => (i === j ? 1n : 0n))
    );
    let base = mat.map(row => row.map(BigInt));
    let exp = BigInt(p);
    // Binary exponentiation: process exponent bits from LSB to MSB
    while (exp > 0n) {
        // If current bit is set, multiply base into result
        if (exp % 2n === 1n) res = matMul(res, base);
        base = matMul(base, base);
        exp /= 2n;
    }
    return res.map(row => row.map(Number));
}

module.exports = { matPow };