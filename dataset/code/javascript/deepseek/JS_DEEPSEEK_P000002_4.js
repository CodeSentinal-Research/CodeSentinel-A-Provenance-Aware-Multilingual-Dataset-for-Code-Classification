/**
 * Subtracts the second integer from the first and returns the result.
 * @param {number} a - The first integer.
 * @param {number} b - The second integer.
 * @returns {number} The result of a - b.
 * @throws {TypeError} If either input is not an integer.
 */
function subtract(a, b) {
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    throw new TypeError('Both inputs must be integers.');
  }
  return a - b;
}

// Entry point for command-line execution
if (require.main === module) {
  const args = process.argv.slice(2);
  if (args.length !== 2) {
    console.error('Usage: node subtract.js <integer1> <integer2>');
    process.exit(1);
  }
  const a = Number(args[0]);
  const b = Number(args[1]);
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    console.error('Both arguments must be valid integers.');
    process.exit(1);
  }
  console.log(subtract(a, b));
}