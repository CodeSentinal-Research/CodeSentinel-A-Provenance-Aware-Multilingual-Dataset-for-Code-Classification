/**
 * Computes the remainder when the first integer is divided by the second.
 * @param {number} a - The dividend.
 * @param {number} b - The divisor.
 * @returns {number} The remainder of `a / b`.
 * @throws {Error} If either argument is not an integer or if the divisor is zero.
 */
function findRemainder(a, b) {
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    throw new Error('Both arguments must be integers.');
  }
  if (b === 0) {
    throw new Error('Cannot divide by zero.');
  }
  return a % b;
}

// Production-ready CLI entry point
if (require.main === module) {
  const [a, b] = process.argv.slice(2).map(Number);
  if (process.argv.length < 4) {
    console.error('Usage: node find-remainder.js <integer1> <integer2>');
    process.exit(1);
  }
  try {
    console.log(findRemainder(a, b));
  } catch (error) {
    console.error(error.message);
    process.exit(1);
  }
}