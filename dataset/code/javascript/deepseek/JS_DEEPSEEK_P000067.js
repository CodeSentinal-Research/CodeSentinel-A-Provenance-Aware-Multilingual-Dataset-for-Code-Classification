/**
 * Calculates the area of a square given its side length.
 * @param {number} side - The length of the square's side. Must be a non-negative finite number.
 * @returns {number} The area of the square.
 * @throws {TypeError} If side is not a finite number.
 * @throws {RangeError} If side is negative.
 */
function calculateSquareArea(side) {
  if (typeof side !== 'number' || !isFinite(side)) {
    throw new TypeError('Side length must be a finite number.');
  }
  if (side < 0) {
    throw new RangeError('Side length cannot be negative.');
  }
  return side * side;
}