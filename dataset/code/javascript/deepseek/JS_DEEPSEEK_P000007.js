/**
 * Checks whether a given integer is even or odd.
 * @param {number | bigint} n - The integer to evaluate.
 * @returns {string} 'Even' if the number is even, 'Odd' if it is odd.
 * @throws {TypeError} If the input is not an integer.
 */
const checkEvenOrOdd = (n) => {
  if (typeof n === 'bigint') {
    return n % 2n === 0n ? 'Even' : 'Odd';
  }