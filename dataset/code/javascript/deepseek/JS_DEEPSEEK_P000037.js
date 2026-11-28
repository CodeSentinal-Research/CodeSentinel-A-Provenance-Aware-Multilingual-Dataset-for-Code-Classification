/**
 * Converts a binary string to its decimal equivalent.
 * @param {string} binary - The binary string to convert (e.g., "1010").
 * @returns {number} The decimal number.
 * @throws {Error} If the input is not a valid binary string.
 */
function binaryToDecimal(binary) {
  if (typeof binary !== 'string' || binary.trim() === '') {
    throw new Error('Input must be a non-empty string.');
  }
  const trimmed = binary.trim();
  // Validate that the string contains only '0' and '1'
  if (!/^[01]+$/.test(trimmed)) {
    throw new Error('Input must be a valid binary string containing only 0s and 1s.');
  }
  return parseInt(trimmed, 2);
}

module.exports = binaryToDecimal;