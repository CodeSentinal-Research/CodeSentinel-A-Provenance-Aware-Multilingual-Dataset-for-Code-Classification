/**
 * Calculates the area of a circle given its radius.
 * @param {number} radius - The radius of the circle. Must be non-negative.
 * @returns {number} The area of the circle. Returns 0 for invalid or negative radius.
 */
function calculateCircleArea(radius) {
  // Validate that radius is a finite number and non-negative
  if (typeof radius !== 'number' || !isFinite(radius) || radius < 0) {
    return 0;
  }
  return Math.PI * radius ** 2;
}

// Example usage (can be run via Node.js with a radius argument)
if (require.main === module) {
  const r = process.argv[2] ? Number(process.argv[2]) : 5;
  console.log(`Area of circle with radius ${r}: ${calculateCircleArea(r)}`);
}