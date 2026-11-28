/**
 * Computes the Greatest Common Divisor (GCD) of two numbers using the Euclidean algorithm.
 * @param {number} a - A positive integer
 * @param {number} b - A positive integer
 * @returns {number} The GCD of a and b
 * @throws {TypeError} If inputs are not integers
 */
function gcd(a, b) {
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    throw new TypeError('gcd requires integer arguments');
  }
  while (b !== 0) {
    const temp = b;
    b = a % b;
    a = temp;
  }
  return Math.abs(a);
}

/**
 * Computes the Least Common Multiple (LCM) of two positive integers.
 * @param {number} a - A positive integer
 * @param {number} b - A positive integer
 * @returns {number} The LCM of a and b
 * @throws {TypeError} If inputs are not positive integers
 */
function lcmTwo(a, b