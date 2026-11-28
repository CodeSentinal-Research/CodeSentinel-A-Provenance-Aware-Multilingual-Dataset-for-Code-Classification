/**
 * Divides two integers and returns the integer division result (truncated toward zero).
 * @param {number} a - The dividend.
 * @param {number} b - The divisor.
 * @returns {number|string} The quotient, or an error message if division by zero or invalid inputs.
 */
function divideTwoNumbers(a, b) {
    // Validate that both inputs are numbers
    if (typeof a !== 'number' || typeof b !== 'number') {
        return 'Error: Both inputs must be numbers.';
    }
    // Handle division by zero
    if (b === 0) {
        return 'Error: Division by zero is not allowed.';
    }
    // Math.trunc handles arbitrary-precision integers and negative numbers correctly
    return Math.trunc(a / b);
}

// Allow the script to be run from the command line
if (require.main === module) {
    const args = process.argv.slice(2);
    if (args.length < 2) {
        console.error('Usage: node divide.js <dividend> <divisor>');
        process.exit(1);
    }
    const a = Number(args[0]);
    const b = Number(args[1]);
    if (isNaN(a) || isNaN(b)) {
        console.error('Error: Both arguments must be valid numbers.');
        process.exit(1);
    }
    const result = divideTwoNumbers(a, b);
    console.log(result);
}

module.exports = divideTwoNumbers;