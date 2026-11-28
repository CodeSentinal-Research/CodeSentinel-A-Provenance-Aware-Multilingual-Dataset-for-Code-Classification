// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function extGcd(a, b) {
    if (b === 0) return [a, 1, 0];
    const [g, x1, y1] = extGcd(b, a % b);
    return [g, y1, x1 - Math.floor(a / b) * y1];
}

// Helper function to evaluate minpositivebezout for problem constraints.
function minPositiveBezout(a, b) {
    const [g, rawX] = extGcd(a, b);
    const stepX = Math.floor(b / g);
    let x = ((rawX % stepX) + stepX) % stepX;
    if (x === 0) x += stepX;
    const y = Math.floor((g - a * x) / b);
    return [x, y];
}

module.exports = { minPositiveBezout };