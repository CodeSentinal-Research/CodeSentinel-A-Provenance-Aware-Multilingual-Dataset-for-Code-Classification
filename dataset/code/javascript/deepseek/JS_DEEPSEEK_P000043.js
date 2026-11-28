/**
 * Prints all integers from 1 to N.
 * 
 * @param {number | string} N - The upper bound (inclusive). 
 *   Non-finite, negative, or zero values result in no output.
 * @returns {void}
 * 
 * @example
 * printNumbersFromOneToN(5); // logs 1, 2, 3, 4, 5
 */
function printNumbersFromOneToN(N) {
  const n = Number(N);
  if (!Number.isFinite(n) || n < 1) {
    return;
  }
  for (let i = 1; i <= Math.floor(n); i++) {
    console.log(i);
  }
}