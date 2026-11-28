// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function extGcd(a, b) {
    if (b === 0n) return [a, 1n, 0n];
    const [g, x1, y1] = extGcd(b, a % b);
    return [g, y1, x1 - (a / b) * y1];
}

// Helper function to evaluate mergecongruences for problem constraints.
function mergeCongruences(r1, m1, r2, m2) {
    const R1 = BigInt(r1), M1 = BigInt(m1);
    const R2 = BigInt(r2), M2 = BigInt(m2);
    const [g, p] = extGcd(M1, M2);
    if ((R2 - R1) % g !== 0n) return [-1, -1];
    const mod = (M1 / g) * M2;
    const step = (R2 - R1) / g;
    const k = (p * step) % (M2 / g);
    const ans = (R1 + k * M1) % mod;
    return [Number(((ans % mod) + mod) % mod), Number(mod)];
}

module.exports = { mergeCongruences };