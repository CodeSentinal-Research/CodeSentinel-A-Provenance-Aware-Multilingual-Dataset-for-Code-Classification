// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function gcd(a, b) {
    while (b !== 0) {
        let t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Computes the Least Common Multiple (LCM).
function lcm(a, b) {
    return (a / gcd(a, b)) * b;
}

// Computes the Least Common Multiple (LCM).
function arrayLcm(arr) {
    return arr.reduce((acc, curr) => lcm(acc, curr));
}

module.exports = { arrayLcm };