/**
 * Subtracts the second number from the first.
 * @param {number} a - The first number.
 * @param {number} b - The second number.
 * @returns {number} The result of a - b.
 * @throws {TypeError} If either argument is not a number.
 */
function subtract(a, b) {
  if (typeof a !== 'number' || typeof b !== 'number') {
    throw new TypeError('Both arguments must be numbers.');
  }
  return a - b;
}

// Entry point for command-line usage
if (require.main === module) {
  const args = process.argv.slice(2);
  if (args.length !== 2) {
    console.error('Please provide exactly two numbers.');
    process.exit(1);
  }
  const numA = Number(args[0]);
  const numB = Number(args[1]);
  if (Number.isNaN(numA) || Number.isNaN(numB)) {
    console.error('Both arguments must be valid numbers.');
    process.exit(1);
  }
  try {
    const result = subtract(numA, numB);
    console.log(result);
  } catch (error) {
    console.error(error.message);
    process.exit(1);
  }
}