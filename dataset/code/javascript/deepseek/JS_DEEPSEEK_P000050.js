/**
 * Calculates the cube of a given integer.
 * @param {number} n - The integer to cube.
 * @returns {number} The cube of n.
 * @throws {TypeError} If n is not a finite number.
 */
const cube = (n) => {
  if (typeof n !== 'number' || !isFinite(n)) {
    throw new TypeError('Input must be a finite number.');
  }
  return n ** 3;
};