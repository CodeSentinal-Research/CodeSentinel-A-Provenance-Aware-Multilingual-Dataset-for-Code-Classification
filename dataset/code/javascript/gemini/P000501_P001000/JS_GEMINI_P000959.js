// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function extGcd(a, b) {
    if (b === 0) return [a, 1, 0];
    const [g, x1, y1] = extGcd(b, a % b);
    return [g, y1, x1 - Math.floor(a / b) * y1];
}

// Solves 'Solve Linear Diophantine Equation' by applying optimal Mathematics - Diophantine Equations logic.
function solveDiophantine(a, b, c) {
    const [g, x, y] = extGcd(a, b);
    if (c % g !== 0) return null;
    const factor = Math.floor(c / g);
    return [x * factor, y * factor];
}

module.exports = { solveDiophantine };