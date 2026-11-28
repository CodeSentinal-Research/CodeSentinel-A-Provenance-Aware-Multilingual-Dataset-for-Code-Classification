/**
 * Prints all factors of a positive integer.
 * @param {number} n - A positive integer
 * @returns {number[]} An array of factors sorted in ascending order
 * @throws {Error} If n is not a positive integer
 */
function printFactors(n) {
  if (typeof n !== 'number' || !Number.isInteger(n) || n <= 0) {
    throw new Error('Input must be a positive integer');
  }
  const factors = [];
  const sqrt = Math.sqrt(n);
  for (let i = 1; i <= sqrt; i++) {
    if (n % i === 0) {
      factors.push(i);
      const complement = n / i;
      if (complement !== i) {
        factors.push(complement);
      }
    }
  }
  factors.sort((a, b) => a - b);
  factors.forEach(factor => console.log(factor));
  return factors;
}

// Example usage:
// printFactors(12); // prints 1, 2, 3, 4, 6, 12 (each on a new line)