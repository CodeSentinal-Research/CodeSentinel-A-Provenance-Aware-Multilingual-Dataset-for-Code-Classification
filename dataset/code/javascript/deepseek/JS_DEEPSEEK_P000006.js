/**
 * Swaps two numbers and prints the result after swapping.
 * @param {number} a - The first integer.
 * @param {number} b - The second integer.
 * @returns {[number, number]} The swapped values [b, a].
 * @throws {TypeError} If either argument is not a number.
 */
function swapNumbers(a, b) {
  if (typeof a !== 'number' || typeof b !== 'number') {
    throw new TypeError('swapNumbers requires two numeric arguments.');
  }
  // Idiomatic swap using destructuring assignment
  [a, b] = [b, a];
  console.log(`After swapping: a = ${a}, b = ${b}`);
  return [a, b];
}

// Example usage (can be run directly or imported):
// swapNumbers(10, 20); // Output: After swapping: a = 20, b = 10