/**
 * Prints all integers from N down to 1.
 * @param {number} N - A positive integer.
 * @returns {void}
 */
function printNumbersFromNToOne(N) {
  if (typeof N !== 'number' || !Number.isInteger(N) || N < 1) {
    return;
  }
  for (let i = N; i >= 1; i--) {
    console.log(i);
  }
}