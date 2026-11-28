/**
 * Performs integer division of two numbers, truncating toward zero.
 * @param {number} a - The dividend.
 * @param {number} b - The divisor.
 * @returns {number} The integer division result.
 * @throws {TypeError} If either argument is not an integer.
 * @throws {Error} If the divisor is zero.
 */
function divideIntegers(a, b) {
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    throw new TypeError('Both arguments must be integers.');
  }
  if (b === 0) {
    throw new Error('Cannot divide by zero.');
  }
  return Math.trunc(a / b);
}

// Allow running as a CLI script: node script.js 10 3
if (require.main === module) {
  const [a, b] = process.argv.slice(2).map(Number);
  try {
    console.log(divideIntegers(a, b));
  } catch (error) {
    console.error(error.message);
    process.exit(1);
  }
}