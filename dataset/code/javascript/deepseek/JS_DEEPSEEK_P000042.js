/**
 * Checks if a given character is a vowel or consonant.
 * @param {string} char - The character to check.
 * @returns {string} - "Vowel", "Consonant", or an error message for invalid input.
 */
function checkVowelOrConsonant(char) {
  // Ensure input is a string of length 1
  if (typeof char !== 'string' || char.length !== 1) {
    return 'Invalid input: please provide a single character.';
  }
  // Convert to lowercase for case-insensitive comparison
  const lowerChar = char.toLowerCase();
  // Check if the character is an alphabetic letter (a-z)
  if (!/^[a-z]$/.test(lowerChar)) {
    return 'Invalid input: not an alphabetic character.';
  }
  // Define vowels
  const vowels = 'aeiou';
  if (vowels.includes(lowerChar)) {
    return 'Vowel';
  }
  return 'Consonant';
}

// Optional: Allow running from command line
if (require.main === module) {
  const input = process.argv[2];
  if (!input) {
    console.error('Usage: node script.js <character>');
    process.exit(1);
  }
  console.log(checkVowelOrConsonant(input));
}