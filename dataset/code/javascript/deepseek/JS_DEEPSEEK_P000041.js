/**
 * Calculates the average of three numbers.
 * @param {number} a - The first number.
 * @param {number} b - The second number.
 * @param {number} c - The third number.
 * @returns {number} The average of the three numbers.
 * @throws {TypeError} If any argument is not a finite number.
 */
function averageOfThree(a, b, c) {
  if (!Number.isFinite(a) || !Number.isFinite(b) || !Number.isFinite(c)) {
    throw new TypeError('All arguments must be finite numbers.');
  }
  return (a + b + c) / 3;
}