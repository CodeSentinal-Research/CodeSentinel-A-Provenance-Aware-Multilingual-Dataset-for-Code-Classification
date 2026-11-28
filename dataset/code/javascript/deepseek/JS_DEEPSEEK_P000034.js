/**
 * Returns the sum of all odd numbers from 1 to N.
 * @param {number} N - The upper bound (inclusive).
 * @returns {number} The sum of odd numbers.
 */
function sumOfOdds(N) {
  const n = Number(N);
  if (!Number.isFinite(n) || n <= 0) return 0;
  const count = Math.floor((n + 1) / 2);
  return count * count;
}