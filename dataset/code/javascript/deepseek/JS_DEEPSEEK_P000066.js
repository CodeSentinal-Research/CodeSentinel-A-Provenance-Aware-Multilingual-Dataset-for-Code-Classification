/**
 * Calculates the area of a triangle given its base and height.
 * @param {number} base - The length of the base (non-negative finite number).
 * @param {number} height - The height of the triangle (non-negative finite number).
 * @returns {number} The area of the triangle.
 * @throws {TypeError} If base or height is not a finite number.
 * @throws {RangeError} If base or height is negative.
 */
function calculateTriangleArea(base, height) {
  if (!Number.isFinite(base) || !Number.isFinite(height)) {
    throw new TypeError('Base and height must be finite numbers.');
  }
  if (base < 0 || height < 0) {
    throw new RangeError('Base and height must be non-negative.');
  }
  return 0.5 * base * height;
}