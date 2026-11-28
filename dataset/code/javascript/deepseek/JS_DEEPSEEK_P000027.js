/**
 * Counts the number of digits in a non-negative integer.
 * @param {number | bigint} n - A non-negative integer
 * @returns {number} The number of digits (returns 1 for input 0)
 * @throws {Error} If input is not a non-negative integer
 */
function countDigits(n) {
  if (typeof n === 'bigint') {
    return String(n).length;
  }
  if (typeof n !== 'number' || !Number.isInteger(n) || n < 0) {
    throw new Error('Input must be a non-negative integer');
  }
  return String(n).length;
}