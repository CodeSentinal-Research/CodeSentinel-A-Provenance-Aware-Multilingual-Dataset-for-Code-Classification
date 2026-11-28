/**
 * Checks if a given number is a perfect number.
 * A perfect number is a positive integer that equals the sum of its proper divisors (excluding itself).
 * Examples: 6 (1+2+3), 28 (1+2+4+7+14), 496, 8128.
 *
 * @param {number} num - The number to test.
 * @returns {boolean} - True if `num` is a perfect number, false otherwise.
 */
function isPerfectNumber(num) {
  if (
    typeof num !== 'number' ||
    !Number.isInteger(num) ||
    num <= 1
  ) {
    return false;
  }

  let sum = 1; // 1 is always a proper divisor for num > 1
  const limit = Math.sqrt(num);

  for (let i = 2; i <= limit; i++) {
    if (num % i === 0) {
      sum += i;
      const other = num / i;
      if (other !== i) {
        sum += other;
      }
    }
  }

  return sum === num;
}

// Example usage (uncomment to test):
// console.log(isPerfectNumber(6));    // true
// console.log(isPerfectNumber(28));   // true
// console.log(isPerfectNumber(496));  // true
// console.log(isPerfectNumber(8128)); // true
// console.log(isPerfectNumber(12));   // false
// console.log(isPerfectNumber(1));    // false
// console.log(isPerfectNumber(0));    // false
// console.log(isPerfectNumber(-6));   // false
// console.log(isPerfectNumber(6.5));  // false