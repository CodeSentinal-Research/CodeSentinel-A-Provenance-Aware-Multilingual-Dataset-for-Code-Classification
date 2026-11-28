/**
 * Converts a positive integer from decimal to binary representation.
 * @param {number} num - A positive integer.
 * @returns {string} The binary representation of the number.
 * @throws {Error} If input is not a positive integer.
 */
function decimalToBinary(num) {
  if (typeof num !== 'number' || !Number.isInteger(num) || num < 0) {
    throw new Error('Input must be a positive integer');
  }
  return num.toString(2);
}