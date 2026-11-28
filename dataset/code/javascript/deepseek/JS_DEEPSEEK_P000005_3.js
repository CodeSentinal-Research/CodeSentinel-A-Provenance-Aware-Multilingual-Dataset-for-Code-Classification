/**
 * Finds the remainder when the first integer (dividend) is divided by the second integer (divisor).
 * @param {number} a - The dividend.
 * @param {number} b - The divisor.
 * @returns {number} The remainder of `a` divided by `b`.
 * @throws {Error} If either input is not an integer, or if the divisor is zero.
 */
function findRemainder(a, b) {
  if (typeof a !== 'number' || typeof b !== 'number') {
    throw new Error('Both inputs must be numbers.');
  }
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    throw new Error('Both inputs must be integers.');
  }
  if (b === 0) {
    throw new Error('Division by zero is not allowed.');
  }
  return a % b;
}

// Allow running directly from the command line: node findRemainder.js 10 3
if (require.main === module) {
  const args = process.argv.slice(2);
  if (args.length !== 2) {
    console.error('Usage: node findRemainder.js <dividend> <divisor>');
    process.exit(1);
  }
  const [a, b] = args.map(Number);
  try {
    const result = findRemainder(a, b);
    console.log(result);
  } catch (err) {
    console.error(err.message);
    process.exit(1);
  }
}