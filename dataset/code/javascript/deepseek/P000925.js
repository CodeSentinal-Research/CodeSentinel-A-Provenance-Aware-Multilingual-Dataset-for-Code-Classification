Sure, here is the JavaScript code:

function binaryToDecimal(binaryString) {
  return parseInt(binaryString, 2);
}

// Example usage:
const binaryInput = process.argv[2];
if (!/^[01]+$/.test(binaryInput)) {
  console.error('Invalid binary string.');
  process.exit(1);
}

const decimalOutput = binaryToDecimal(binaryInput);
console.log(decimalOutput);

This code takes a binary string as input from the command line arguments, checks if the input string is a binary number, and if so, converts it to its decimal equivalent. If the input string is not a binary number, it logs an error message to the console and exits.

To run the code, you can use Node.js:

node binaryToDecimal.js 1010111

This will convert the binary string "1010111" to its decimal equivalent (37).