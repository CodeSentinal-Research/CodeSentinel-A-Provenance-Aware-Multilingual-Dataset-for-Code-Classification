// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function extGcd(a, b) {
    if (b === 0) return [a, 1, 0];
    const [g, x1, y1] = extGcd(b, a % b);
    return [g, y1, x1 - Math.floor(a / b) * y1];
}

// Solves 'Find One Diophantine Solution' by applying optimal Mathematics - Diophantine Equations logic.
function findOneSolution(a, b, c) {
    const [g, x, y] = extGcd(a, b);
    if (c % g !== 0) return [-1, -1];
    const f = Math.floor(c / g);
    return [x * f, y * f];
}

module.exports = { findOneSolution };