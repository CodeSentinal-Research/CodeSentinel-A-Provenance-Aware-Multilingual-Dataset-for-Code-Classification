/**
 * Returns the maximum of two numbers.
 * @param {number} a - The first integer.
 * @param {number} b - The second integer.
 * @returns {number} The larger of the two numbers.
 * @throws {TypeError} If either argument is not a finite number.
 */
function findMax(a, b) {
  if (typeof a !== 'number' || typeof b !== 'number') {
    throw new TypeError('Both arguments must be numbers.');
  }
  if (!Number.isFinite(a) || !Number.isFinite(b)) {
    throw new TypeError('Both arguments must be finite numbers.');
  }
  return Math.max(a, b);
}

// Standalone CLI execution
if (require.main === module) {
  try {
    const [a, b] = process.argv.slice(2).map(Number);
    console.log(findMax(a, b));
  } catch (error) {
    console.error(error.message);
    process.exit(1);
  }
}