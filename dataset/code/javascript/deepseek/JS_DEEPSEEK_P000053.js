/**
 * Converts a single character to its uppercase equivalent.
 * @param {string} char - The character to convert.
 * @returns {string} The uppercase version of the character.
 * @throws {TypeError} If input is not a single character string.
 */
function toUpperCase(char) {
  if (typeof char !== 'string' || char.length !== 1) {
    throw new TypeError('Input must be a single character string.');
  }
  return char.toUpperCase();
}

// Production-ready export (for Node.js / bundlers):
// module.exports = toUpperCase;