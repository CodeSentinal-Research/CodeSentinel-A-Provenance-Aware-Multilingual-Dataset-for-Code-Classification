/**
 * Calculates simple interest.
 * @param {number} principal - The principal amount (must be non-negative).
 * @param {number} rate - The interest rate per period (non-negative, in percent).
 * @param {number} time - The time duration (non-negative, in same units as rate).
 * @returns {number} The simple interest calculated.
 * @throws {TypeError} If any argument is not a number or is negative.
 */
function calculateSimpleInterest(principal, rate, time) {
  if (
    typeof principal !== 'number' ||
    typeof rate !== 'number' ||
    typeof time !== 'number' ||
    principal < 0 ||
    rate < 0 ||
    time < 0
  ) {
    throw new TypeError('All arguments must be non-negative numbers.');
  }
  return (principal * rate * time) / 100;
}

// Example usage:
// const interest = calculateSimpleInterest(1000, 5, 2); // 100
// console.log(interest);