// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function gcd(a, b) {
    while (b !== 0) {
        let temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Computes the Least Common Multiple (LCM).
function lcm(a, b) {
    if (a === 0 || b === 0) return 0;
    return (a / gcd(a, b)) * b;
}

module.exports = { lcm };