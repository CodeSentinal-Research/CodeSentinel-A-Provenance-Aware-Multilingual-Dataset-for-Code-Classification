/**
 * Returns the maximum of three numbers.
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @returns {number} The largest of the three
 * @throws {TypeError} If any argument is not a finite number
 */
function maxOfThree(a, b, c) {
  if (
    typeof a !== 'number' ||
    typeof b !== 'number' ||
    typeof c !== 'number' ||
    !Number.isFinite(a) ||
    !Number.isFinite(b) ||
    !Number.isFinite(c)
  ) {
    throw new TypeError('All arguments must be finite numbers.');
  }
  return Math.max(a, b, c);
}

// If run as a standalone program
if (require.main === module) {
  const args = process.argv.slice(2);
  if (args.length !== 3) {
    console.error('Usage: node script.js <num1> <num2> <num3>');
    process.exit(1);
  }
  const [a, b, c] = args.map(Number);
  try {
    const result = maxOfThree(a, b, c);
    console.log(result);
  } catch (err) {
    console.error(err.message);
    process.exit(1);
  }
}