/**
 * Calculates the perimeter of a square given its side length.
 * @param {number} side - The length of the square's side.
 * @returns {number} The perimeter of the square.
 * @throws {TypeError} If side is not a number, is not finite, or is negative.
 */
function calculatePerimeter(side) {
  if (typeof side !== 'number' || !isFinite(side) || side < 0) {
    throw new TypeError('Side length must be a non-negative number.');
  }
  return 4 * side;
}

// Example usage:
// const perimeter = calculatePerimeter(5); // 20