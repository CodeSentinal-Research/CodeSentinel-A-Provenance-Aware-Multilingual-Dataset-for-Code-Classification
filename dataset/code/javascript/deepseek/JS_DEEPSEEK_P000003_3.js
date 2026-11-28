// Multiply two integers provided as command-line arguments and print the product.

const args = process.argv.slice(2);

if (args.length < 2) {
  console.error('Usage: node multiply.js <integer1> <integer2>');
  process.exit(1);
}

const [num1Str, num2Str] = args;

// Helper to validate and parse an integer string
function parseInteger(str) {
  const n = Number(str);
  if (Number.isInteger(n)) return n;
  // Also accept strings that represent integers (e.g., "42", "-7")
  if (/^-?\d+$/.test(str)) return parseInt(str, 10);
  return null;
}

const num1 = parseInteger(num1Str);
const num2 = parseInteger(num2Str);

if (num1 === null || num2 === null) {
  console.error('Error: Both arguments must be valid integers.');
  process.exit(1);
}

const product = num1 * num2;
console.log(product);