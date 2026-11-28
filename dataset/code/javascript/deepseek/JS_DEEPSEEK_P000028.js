/**
 * Computes x raised to the power n.
 * @param {number} x - The base number.
 * @param {number} n - The exponent (integer).
 * @returns {number} The result of x^n.
 */
function myPow(x, n) {
    if (n === 0) return 1;
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    let result = 1;
    let currentProduct = x;
    let exponent = n;
    while (exponent > 0) {
        if (exponent % 2 === 1) {
            result *= currentProduct;
        }
        currentProduct *= currentProduct;
        exponent = Math.floor(exponent / 2);
    }
    return result;
}