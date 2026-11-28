/**
 * Finds the highest common factor (HCF) of two positive integers using the Euclidean algorithm.
 * @param {number} a - A positive integer.
 * @param {number} b - A positive integer.
 * @returns {number} The highest common factor of a and b.
 * @throws {TypeError} If either input is not a positive integer.
 */
function findHCF(a, b) {
  if (!Number.isInteger(a) || a < 1 || !Number.isInteger(b) || b < 1) {
    throw new TypeError('Both inputs must be positive integers.');
  }
  while (b !== 0) {
    [a, b] = [b, a % b];
  }
  return a;
}

// Example usage:
// const hcf = findHCF(48, 18);
// console.log(hcf); // 6