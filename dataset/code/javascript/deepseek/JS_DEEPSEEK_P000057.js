/**
 * Calculates the sum of the first N odd numbers.
 * 
 * The sum of the first N odd numbers is given by the well-known formula: N^2.
 * This function validates input and handles edge cases gracefully.
 * 
 * @param {number} n - The number of odd terms to sum. Must be a non-negative integer.
 * @returns {number} The sum of the first N odd numbers.
 * @throws {TypeError} If `n` is not a number or is not an integer.
 * @throws {RangeError} If `n` is negative.
 * 
 * @example
 * sumOfFirstNOddNumbers(1); // 1
 * sumOfFirstNOddNumbers(3); // 9 (1 + 3 + 5)
 * sumOfFirstNOddNumbers(0); // 0
 */
function sumOfFirstNOddNumbers(n) {
  if (typeof n !== 'number') {
    throw new TypeError('Input must be a number.');
  }
  if (!Number.isInteger(n)) {
    throw new TypeError('Input must be an integer.');
  }
  if (n < 0) {
    throw new RangeError('Input must be a non-negative integer.');
  }
  // Sum of the first N odd numbers = N * N
  return n * n;
}

// Optional: Simple CLI interface for standalone execution
if (require.main === module) {
  const readline = require('readline');
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  rl.question('Enter a non-negative integer N: ', (input) => {
    const n = Number(input);
    try {
      const result = sumOfFirstNOddNumbers(n);
      console.log(`The sum of the first ${n} odd numbers is ${result}.`);
    } catch (err) {
      console.error('Error:', err.message);
    } finally {
      rl.close();
    }
  });
}