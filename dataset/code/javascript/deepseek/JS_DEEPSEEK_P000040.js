/**
 * Prints all printable ASCII characters (codes 32 through 126) to the console.
 * @returns {string[]} - Array containing all printed characters for further use.
 */
function printPrintableAscii() {
  const chars = [];
  for (let i = 32; i <= 126; i++) {
    const char = String.fromCodePoint(i); // safely converts code point to character
    console.log(char);
    chars.push(char);
  }
  return chars;
}

// Execute the function to print all printable ASCII characters
const printed = printPrintableAscii();