/**
 * Divides two integers and returns the integer division result.
 * The result is truncated toward zero, matching the behavior of C/Java integer division.
 * @param {number} a - The dividend.
 * @param {number} b - The divisor.
 * @returns {number} The integer quotient.
 * @throws {Error} If the divisor is zero.
 * @throws {TypeError} If arguments are not numbers or not integers.
 */
function divideIntegers(a, b) {
  if (typeof a !== 'number' || typeof b !== 'number') {
    throw new TypeError('Both arguments must be numbers.');
  }
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    throw new TypeError('Both arguments