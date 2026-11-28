/**
 * Returns the ASCII value of a given character.
 * @param {string|string[]} char - The character to get the ASCII value from.
 * @returns {number|undefined} The ASCII value, or undefined if input is invalid.
 */
function getASCIIValue(char) {
  if (typeof char === 'undefined' || char === null) {
    return undefined;
  }
  const s = String(char);
  if (s.length === 0) {
    return undefined;
  }
  // If multiple characters, take the first one
  const firstChar = s[0];
  return firstChar.charCodeAt(0);
}

// If run directly from command line
if (require.main === module) {
  const char = process.argv[2];
  const value = getASCIIValue(char);
  if (value !== undefined) {
    console.log(`The ASCII value of "${char}" is ${value}.`);
  } else {
    console.error('Invalid input. Please provide a single character.');
    process.exit(1);
  }
}