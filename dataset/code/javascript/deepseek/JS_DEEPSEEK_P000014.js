/**
 * Calculates the area of a rectangle.
 *
 * @param {number} length - The length of the rectangle. Must be a finite, non-negative number.
 * @param {number} breadth - The breadth of the rectangle. Must be a finite, non-negative number.
 * @returns {number} The area of the rectangle (length × breadth).
 * @throws {TypeError} If either argument is not a number.
 * @throws {RangeError} If either argument is negative or not finite.
 */
function calculateRectangleArea(length, breadth) {
  if (typeof length !== 'number' || typeof breadth !== 'number') {
    throw new TypeError('Length and breadth must be numbers.');
  }
  if (!Number.isFinite(length) || !Number.isFinite(breadth)) {
    throw new RangeError('Length and breadth must be finite numbers.');
  }
  if (length < 0 || breadth < 0) {
    throw new RangeError('Length and breadth must be non-negative.');
  }
  return length * breadth;
}

module.exports = { calculateRectangleArea };