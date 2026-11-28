/**
 * Calculates the perimeter of a rectangle.
 * @param {number} length - The length of the rectangle. Must be a non-negative finite number.
 * @param {number} breadth - The breadth of the rectangle. Must be a non-negative finite number.
 * @returns {number} The perimeter of the rectangle.
 * @throws {TypeError} If either length or breadth is not a finite number.
 * @throws {RangeError} If either length or breadth is negative.
 */
function calculateRectanglePerimeter(length, breadth) {
  if (typeof length !== 'number' || typeof breadth !== 'number') {
    throw new TypeError('Length and breadth must be numbers.');
  }
  if (
    Number.isNaN(length) ||
    Number.isNaN(breadth) ||
    !Number.isFinite(length) ||
    !Number.isFinite(breadth)
  ) {
    throw new TypeError('Length and breadth must be finite numbers.');
  }
  if (length < 0 || breadth < 0) {
    throw new RangeError('Length and breadth must be non-negative.');
  }
  return 2 * (length + breadth);
}

module.exports = { calculateRectanglePerimeter };