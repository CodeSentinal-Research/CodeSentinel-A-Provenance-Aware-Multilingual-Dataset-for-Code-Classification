/**
 * Subtracts the second number from the first number.
 * 
 * @param {number} a - The first integer (minuend).
 * @param {number} b - The second integer (subtrahend).
 * @returns {number} The result of a - b.
 * 
 * @example
 * subtract(10, 3); // 7
 * subtract(-5, 2); // -7
 * subtract(0, 0); // 0
 */
function subtract(a, b) {
  // Validate that both inputs are numbers
  if (typeof a !== 'number' || typeof b !== 'number') {
    throw new TypeError('Both arguments must be numbers.');
  }

  // Return the difference
  return a - b;
}

// If running this module directly, demonstrate usage
if (require.main === module) {
  // Simple CLI interface
  const args = process.argv.slice(2);
  
  if (args.length !== 2) {
    console.error('Usage: node subtract.js <number1> <number2>');
    process.exit(1);
  }

  try {
    const num1 = Number(args[0]);
    const num2 = Number(args[1]);

    if (isNaN(num1) || isNaN(num2)) {
      throw new Error('Invalid input: both arguments must be valid numbers.');
    }

    const result = subtract(num1, num2);
    console.log(`Result: ${result}`);
  } catch (error) {
    console.error(error.message);
    process.exit(1);
  }
}

module.exports = { subtract };