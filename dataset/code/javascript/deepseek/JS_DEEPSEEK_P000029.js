'use strict';

/**
 * Computes the greatest common divisor (GCD) of two positive integers
 * using the iterative Euclidean algorithm.
 * @param {number} a - A positive integer
 * @param {number} b - A positive integer
 * @returns {number} The greatest common divisor of a and b
 * @throws {TypeError} If inputs are not positive integers
 */
function gcd(a, b) {
  if (!Number.isInteger(a) || !Number.isInteger(b) || a < 1 || b < 1) {
    throw new TypeError('Both inputs must be positive integers.');
  }
  while (b !== 0) {
    const remainder = a % b;
    a = b;
    b = remainder;
  }
  return a;
}