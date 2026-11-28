// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function gcd(a, b) {
    while (b !== 0) {
        let t = b;
        b = a % b;
        a = t;
    }
    return Math.abs(a);
}

// Helper function to evaluate verifybezout for problem constraints.
function verifyBezout(a, b, x, y) {
    return a * x + b * y === gcd(a, b);
}

module.exports = { verifyBezout };