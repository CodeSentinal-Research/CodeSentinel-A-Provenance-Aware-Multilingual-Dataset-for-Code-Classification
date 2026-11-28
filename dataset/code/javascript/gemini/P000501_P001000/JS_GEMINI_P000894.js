// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function gcd(a, b) {
    while (b !== 0) {
        let temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

module.exports = { gcd };