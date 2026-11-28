/**
 * Finds the remainder when the first integer is divided by the second.
 * @param {number} dividend - The first integer.
 * @param {number} divisor - The second integer.
 * @returns {number} The remainder.
 * @throws {Error} If divisor is zero.
 */
function findRemainder(dividend, divisor) {
  if (divisor === 0) {
    throw new Error('Division by zero is not allowed.');
  }
  return dividend % divisor;
}

// If run directly from command line
if (require.main === module) {
  const args = process.argv.slice(2);
  if (args.length !== 2) {
    console.error('Usage: node findRemainder.js <dividend> <divisor>');
    process.exit(1);
  }
  const [dividend, divisor] = args.map(Number);
  if (isNaN(dividend) || isNaN(divisor)) {
    console.error('Both arguments must be valid integers.');
    process.exit(1);
  }
  try {
    const result = findRemainder(dividend, divisor);
    console.log(result);
  } catch (e) {
    console.error(e.message);
    process.exit(1);
  }
}

module.exports = { findRemainder };