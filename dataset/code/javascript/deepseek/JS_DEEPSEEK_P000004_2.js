/**
 * Performs integer division of two numbers, truncating towards zero.
 * @param {number} a - The dividend.
 * @param {number} b - The divisor.
 * @returns {number} The integer division result.
 * @throws {Error} If divisor is zero.
 * @throws {TypeError} If inputs are not integers.
 */
function divideIntegers(a, b) {
  if (typeof a !== 'number' || typeof b !== 'number') {
    throw new TypeError('Both arguments must be numbers.');
  }
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    throw new TypeError('Both arguments must be integers.');
  }
  if (b === 0) {
    throw new Error('Division by zero is undefined.');
  }
  return Math.trunc(a / b);
}

// CLI entry point for standalone execution
if (require.main === module) {
  const input = process.argv.slice(2);
  if (input.length !== 2) {
    console.error('Usage: node script.js <integer1> <integer2>');
    process.exit(1);
  }
  const [a, b] = input.map(Number);
  try {
    const result = divideIntegers(a, b);
    console.log(result);
  } catch (error) {
    console.error(error.message);
    process.exit(1);
  }
}