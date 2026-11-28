/**
 * Calculates the compound interest earned on an principal amount.
 *
 * @param {number} principal - The initial amount of money (must be non-negative).
 * @param {number} rate - Annual interest rate as a decimal (e.g., 0.05 for 5%).
 * @param {number} time - Time in years (must be non-negative).
 * @param {number} [frequency=1] - Number of times interest is compounded per year (default: annually).
 * @returns {number} The compound interest earned (total amount minus principal).
 * @throws {TypeError} If any argument is not a finite number.
 * @throws {RangeError} If principal, rate, or time is negative,