/**
 * Reverses the digits of a given integer.
 * Handles negative numbers and trailing zeros.
 * @param {number} x - The integer to reverse.
 * @returns {number} The reversed integer, or 0 if it exceeds a 32-bit signed integer range.
 */
function reverseInteger(x) {
  const sign = Math.sign(x);
  const reversed = Math.abs(x).toString().split('').reverse().join('');
  const result = parseInt(reversed, 10) * sign;

  // Clamp to 32-bit signed integer range (common production constraint)
  if (result < -2147483648 || result > 2147483647) {
    return 0;
  }
  return result;
}