/**
 * Adds two integers and returns their sum.
 * 
 * @param {number} num1 The first integer.
 * @param {number} num2 The second integer.
 * @returns {number} The sum of num1 and num2.
 */
function addTwoNumbers(num1, num2) {
    // Check if both inputs are integers
    if (!Number.isInteger(num1) || !Number.isInteger(num2)) {
        throw new Error('Both inputs must be integers.');
    }
    
    // Calculate and return the sum
    return num1 + num2;
}

// Example usage:
try {
    const num1 = 5;
    const num2 = 10;
    const sum = addTwoNumbers(num1, num2);
    console.log(`The sum of ${num1} and ${num2} is: ${sum}`);
} catch (error) {
    console.error(error.message);
}