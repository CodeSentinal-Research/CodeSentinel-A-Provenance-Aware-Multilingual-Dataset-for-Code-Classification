/**
 * Counts the number of odd digits in a non-negative integer.
 * @param {number} n - A non-negative integer
 * @returns {number} The count of odd digits (1, 3, 5, 7, 9)
 * @throws {Error} If input is not a non-negative integer
 */
function countOddDigits(n) {
  if (typeof n !== 'number' || n < 0 || !Number.isInteger(n)) {
    throw new Error('Input must be a non-negative integer');
  }
  let count = 0;
  while (n > 0) {
    const digit = n % 10;
    if (digit % 2 !== 0) {
      count++;
    }
    n = Math.floor(n / 10);
  }
  return count;
}

// Example usage (can be removed or kept for testing):
// console.log(countOddDigits(0));            // 0
// console.log(countOddDigits(12345));        // 3
// console.log(countOddDigits(2468));         // 0
// console.log(countOddDigits(13579));        // 5
// console.log(countOddDigits(10101));        // 3