const factorials = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]; // 0! to 9!

/**
 * Checks if a number is a strong number.
 * A strong number is one where the sum of the factorials of its digits equals the number itself.
 * @param {number} n - The number to check.
 * @returns {boolean} - True if the number is a strong number, false otherwise.
 */
const isStrongNumber = (n) => {
  if (n < 0) return false;
  if (n === 0) return false;
  let original = n;
  let sum = 0;
  while (n > 0) {
    const digit = n % 10;
    sum += factorials[digit];
    n = Math.floor(n / 10);
  }
  return sum === original;
};

// Example usage:
// console.log(isStrongNumber(145)); // true
// console.log(isStrongNumber(1));   // true
// console.log(isStrongNumber(2));   // true
// console.log(isStrongNumber(0));   // false
// console.log(isStrongNumber(123)); // false