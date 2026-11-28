/**
 * Checks if an integer is a palindrome.
 * 
 * @param {number} num - The integer to evaluate.
 * @returns {boolean} - True if `num` reads the same forward and backward.
 * 
 * @example
 * isPalindromeNumber(121);   // true
 * isPalindromeNumber(-121);  // false
 * isPalindromeNumber(10);    // false
 * isPalindromeNumber(0);     // true
 */
function isPalindromeNumber(num) {
  // Negative numbers are not palindromes (e.g., -121 → "121-")
  if (num < 0) return false;

  // Convert to string, reverse, and compare
  const str = num.toString();
  return str === str.split('').reverse().join('');
}

// When run directly, allow CLI input
if (require.main === module) {
  const input = process.argv[2];
  if (input === undefined) {
    console.error('Usage: node palindrome.js <integer>');
    process.exit(1);
  }
  const num = Number(input);
  if (!Number.isInteger(num)) {
    console.error('Error: Input must be an integer.');
    process.exit(1);
  }
  console.log(isPalindromeNumber(num));
}