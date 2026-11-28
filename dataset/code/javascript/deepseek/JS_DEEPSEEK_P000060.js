/**
 * Counts the number of even digits in a non-negative integer.
 * @param {number} n - A non-negative integer
 * @returns {number} The count of even digits (0, 2, 4, 6, 8)
 * @throws {TypeError} If input is not a non-negative integer
 */
function countEvenDigits(n) {
  if (!Number.isInteger(n) || n < 0) {
    throw new TypeError('Input must be a non-negative integer');
  }
  return [...String(n)].filter(digit => +digit % 2 === 0).length;
}