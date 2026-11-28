// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function gcd(a, b) {
    while (b !== 0) {
        let t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Helper function to evaluate reducefraction for problem constraints.
function reduceFraction(num, den) {
    const g = gcd(num, den);
    return [num / g, den / g];
}

module.exports = { reduceFraction };