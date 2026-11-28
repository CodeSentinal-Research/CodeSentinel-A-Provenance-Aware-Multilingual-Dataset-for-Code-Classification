/**
 * Adds two integers and returns their sum.
 * @param {number|string} a - The first integer.
 * @param {number|string} b - The second integer.
 * @returns {number} The sum of a and b.
 * @throws {TypeError} If either input is not a valid integer.
 */
function addTwoNumbers(a, b) {
  const numA = Number(a);
  const numB = Number(b);

  if (!Number.isFinite(numA) || !Number.isFinite(numB)) {
    throw new TypeError('Both inputs must be valid numbers.');
  }

  if (!Number.isInteger(numA) || !Number.isInteger(numB)) {
    throw new TypeError('Both inputs must be integers.');
  }

  return numA + numB;
}

// If this script is run directly from the command line
if (require.main === module) {
  const args = process.argv.slice(2);

  if (args.length < 2) {
    console.error('Usage: node addTwoNumbers.js <integer1> <integer2>');
    process.exit(1);
  }

  try {
    const a = parseInt(args[0], 10);
    const b = parseInt(args[1], 10);

    if (isNaN(a) || isNaN(b)) {
      throw new Error('Invalid integer input. Please provide valid integers.');
    }

    console.log(a + b);
  } catch (error) {
    console.error(error.message);
    process.exit(1);
  }
}

module.exports = { addTwoNumbers };