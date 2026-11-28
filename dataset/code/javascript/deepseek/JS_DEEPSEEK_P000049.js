/**
 * Returns the square of a finite integer.
 * @param {number} n - The integer to square.
 * @returns {number} The square of n.
 * @throws {TypeError} If n is not a finite integer.
 */
function square(n) {
  if (typeof n !== 'number' || !Number.isFinite(n) || !Number.isInteger(n)) {
    throw new TypeError('Input must be a finite integer.');
  }
  return n * n;
}