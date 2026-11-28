/**
 * Calculates the sum of squares of the first N natural numbers.
 * Uses the closed-form formula: N(N + 1)(2N + 1) / 6
 *
 * @param {number} n - A non-negative integer representing the count of natural numbers.
 * @returns {number} The sum 1^2 + 2^2 + ... + n^2.
 * @throws {TypeError} If n is not a non-negative integer.
 */
const sumOfSquares = (n) => {
  if (!Number.isInteger(n) || n < 0) {
    throw new TypeError('Input must be a non-negative integer.');
  }
  return (n * (n + 1) * (2 * n + 1)) / 6;
};