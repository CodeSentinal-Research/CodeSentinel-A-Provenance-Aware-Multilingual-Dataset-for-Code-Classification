// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function extGcd(a, b) {
    if (b === 0) return [a, 1, 0];
    const [g, x1, y1] = extGcd(b, a % b);
    return [g, y1, x1 - Math.floor(a / b) * y1];
}

// Helper function to evaluate modinv for problem constraints.
function modInv(a, m) {
    const [g, x] = extGcd(a, m);
    if (g !== 1) return -1;
    return ((x % m) + m) % m;
}

module.exports = { modInv };