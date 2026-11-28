/**
 * Calculates the circumference of a circle given its radius.
 * @param {number} radius - The radius of the circle.
 * @returns {number} The circumference. Returns 0 for invalid or negative radius.
 */
function calculateCircumference(radius) {
  if (typeof radius !== 'number' || !Number.isFinite(radius) || radius < 0) {
    return 0;
  }
  return 2 * Math.PI * radius;
}

module.exports = { calculateCircumference };