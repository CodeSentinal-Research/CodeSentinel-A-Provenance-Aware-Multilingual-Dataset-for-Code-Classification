/**
 * Checks whether a given character is uppercase or lowercase.
 * 
 * @param {string} char - A single character string to evaluate.
 * @returns {string} - 'uppercase', 'lowercase', or 'not an alphabetic character'.
 * @throws {Error} - If input is not a single character string.
 */
function checkCase(char) {
  // Validate input: must be a string of length 1
  if (typeof char !== 'string' || char.length !== 1) {
    throw new Error('Input must be a single character string.');
  }
  
  // Get the Unicode code point of the character
  const code = char.charCodeAt(0);
  
  // Check ranges for uppercase (A-Z) and lowercase (a-z)
  if (code >= 65 && code <= 90) {
    return 'uppercase';
  } else if (code >= 97 && code <= 122) {
    return 'lowercase';
  } else {
    return 'not an alphabetic character';
  }
}

// Example usage (uncomment to test):
// console.log(checkCase('A')); // uppercase
// console.log(checkCase('z')); // lowercase
// console.log(checkCase('5')); // not an alphabetic character