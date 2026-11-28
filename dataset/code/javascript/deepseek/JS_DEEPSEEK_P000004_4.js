/**
 * Performs integer division of two numbers, truncating toward zero.
 * Handles edge cases: division by zero, non-integer inputs, and invalid types.
 * @param {number} a - The dividend.
 * @param {number} b - The divisor.
 * @returns {number} The integer division result.
 * @throws {TypeError} If inputs are not numbers or not integers.
 * @throws {Error} If the divisor is zero.
 */
function divideIntegers(a, b) {
  if (typeof a !== 'number' || typeof b !== 'number') {
    throw new TypeError('Both inputs must be numbers.');
  }
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    throw new TypeError('Both inputs must be integers.');
  }
  if (b === 0) {
    throw new Error('Division by zero is not allowed.');
  }
  // Math.trunc truncates toward zero, matching typical integer division semantics
  return Math.trunc(a / b);
}

// Production-ready CLI entry point
if (require.main === module) {
  const args = process.argv.slice(2);
  if (args.length !== 2) {
    console.error('Usage: node <script> <integer1> <integer2>');
    process.exit(1);
  }
  const [a, b] = args.map(Number);
  try {
    const result = divideIntegers(a, b);
    console.log(result);
  } catch (error) {
    console.error(error.message);
    process.exit(1);
  }
}