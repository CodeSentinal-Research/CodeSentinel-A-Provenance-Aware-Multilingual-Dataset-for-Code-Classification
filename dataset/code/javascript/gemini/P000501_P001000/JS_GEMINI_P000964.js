// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function extGcd(a, b) {
    if (b === 0n) return [a, 1n, 0n];
    const [g, x1, y1] = extGcd(b, a % b);
    return [g, y1, x1 - (a / b) * y1];
}

// Helper function to evaluate crt for problem constraints.
function crt(num, rem) {
    let prod = 1n;
    const numB = num.map(BigInt);
    const remB = rem.map(BigInt);
    for (const n of numB) prod *= n;
    let result = 0n;
    for (let i = 0; i < numB.length; i++) {
        const pp = prod / numB[i];
        const [g, inv] = extGcd(pp, numB[i]);
        const invMod = ((inv % numB[i]) + numB[i]) % numB[i];
        result = (result + remB[i] * pp * invMod) % prod;
    }
    return Number(result);
}

module.exports = { crt };