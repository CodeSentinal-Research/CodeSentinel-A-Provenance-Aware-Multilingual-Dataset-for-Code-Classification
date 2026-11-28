// Calculates modular exponentiation (base^exp % mod) efficiently.
function isPowerOfTwo(n) {
    return n > 0 && (n & (n - 1)) === 0;
}

module.exports = { isPowerOfTwo };