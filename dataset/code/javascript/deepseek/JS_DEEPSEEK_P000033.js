/**
 * Calculates the sum of all even numbers from 1 to N.
 * @param {number} N - The upper limit (inclusive).
 * @returns {number} The sum of even numbers up to N.
 */
function sumEvenNumbers(N) {
  // Validate input: must be a finite number and at least 2
  if (typeof N !== 'number' || !isFinite(N) || N < 2) {
    return 0;
  }
  // k is the count of even numbers up to N (floor(N/2))
  const k = Math.floor(N / 2);
  // Sum of the first k even numbers = k * (k + 1)
  return k * (k + 1);
}

// Example usage:
// console.log(sumEvenNumbers(10)); // 30 (2+4+6+8+10)