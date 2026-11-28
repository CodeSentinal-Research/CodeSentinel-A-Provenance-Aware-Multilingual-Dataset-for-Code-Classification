// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function extGcd(a, b) {
    if (b === 0) return [a, 1, 0];
    const [g, x1, y1] = extGcd(b, a % b);
    const x = y1;
    const y = x1 - Math.floor(a / b) * y1;
    return [g, x, y];
}

module.exports = { extGcd };