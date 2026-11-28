// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function gcd(a, b) {
    while (b !== 0) {
        let t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function arrayGcd(arr) {
    return arr.reduce((acc, curr) => gcd(acc, curr));
}

module.exports = { arrayGcd };