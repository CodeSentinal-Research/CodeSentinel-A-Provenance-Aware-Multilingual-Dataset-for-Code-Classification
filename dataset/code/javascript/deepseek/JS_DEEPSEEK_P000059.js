/**
 * Returns the product of the digits of a non-negative integer.
 * @param {number} n - The non-negative integer
 * @returns {number} The product of the digits
 * @throws {TypeError} If input is not a non-negative integer
 */
const productOfDigits = (n) => {
  if (typeof n !== 'number' || !Number.isInteger(n) || n < 0) {
    throw new TypeError('Input must be a non-negative integer');
  }
  if (n === 0) return 0;
  return String(n).split('').reduce((product, digit) => product * Number(digit), 1);
};