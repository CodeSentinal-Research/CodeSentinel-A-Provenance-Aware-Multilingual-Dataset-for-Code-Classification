/**
 * Checks whether three given side lengths can form a valid triangle.
 * Uses the triangle inequality theorem: the sum of any two sides must be strictly greater than the third.
 * @param {number} a - length of the first side
 * @param {number} b - length of the second side
 * @param {number} c - length of the third side
 * @returns {boolean} true if the sides form a valid triangle, false otherwise
 */
function isValidTriangle(a, b, c) {
  // Reject non-finite numbers (NaN, Infinity, -Infinity)
  if (!Number.isFinite(a) || !Number.isFinite(b) || !Number.isFinite(c)) {
    return false;
  }
  // All sides must be positive
  if (a <= 0 || b <= 0 || c <= 0) {
    return false;
  }
  // Triangle inequality theorem
  return (a + b > c) && (a + c > b) && (b + c > a);
}

module.exports = isValidTriangle;