/**
 * Checks if a number is divisible by another number.
 * @param {number} dividend - The number to be divided.
 * @param {number} divisor - The number to divide by.
 * @returns {boolean} True if `dividend` is divisible by `divisor`, false otherwise.
 * @throws {TypeError} If either argument is not a finite number.
 */
function isDivisible(dividend, divisor) {
  if (typeof dividend !== 'number' || typeof divisor !== 'number') {
    throw new TypeError('Both arguments must be numbers.');
  }
  if (!Number.isFinite(dividend) || !Number.isFinite(divisor)) {
    throw new TypeError('Both arguments must be finite numbers.');
  }
  if (divisor === 0) {
    return false; // Division by zero is undefined, so not divisible
  }
  return dividend % divisor === 0;
}