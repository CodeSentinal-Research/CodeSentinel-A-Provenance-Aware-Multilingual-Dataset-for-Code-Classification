/**
 * Computes the greatest common divisor of two numbers using the Euclidean algorithm.
 * @param {number} a - A positive integer.
 * @param {number} b - A positive integer.
 * @returns {number} The greatest common divisor of a and b.
 */
function gcd(a, b) {
  while (b !== 0) {
    const temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

/**
 * Computes the least common multiple of two positive integers.
 * @param {number} a - A positive integer.
 * @param {number} b - A positive integer.
 * @returns {number} The least common multiple of a and b.
 * @throws {Error} If either argument is not a positive integer.
 */
function lcm(a, b) {
  if (!Number.isInteger(a) || a <= 0 || !Number.isInteger(b) || b <= 0) {
    throw new Error('Both arguments must be positive integers.');
  }
  return Math.abs(a * b) / gcd(a, b);
}

// Example usage:
// console.log(lcm(12, 18)); // 36

module.exports = { lcm, gcd };