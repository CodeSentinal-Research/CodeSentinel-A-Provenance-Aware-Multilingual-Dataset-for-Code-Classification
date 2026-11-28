/**
 * Determines if a given positive integer is a prime number.
 * @param {number} n - A positive integer (n >= 1)
 * @returns {boolean} - True if n is prime, false otherwise.
 */
function isPrime(n) {
  if (n <= 1 || !Number.isInteger(n)) return false;
  if (n === 2) return true;
  if (n % 2 === 0) return false;
  for (let i = 3; i * i <= n; i += 2) {
    if (n % i === 0) return false;
  }
  return true;
}