#!/usr/bin/env node

// Validate that two arguments are provided
if (process.argv.length < 4) {
  console.error('Usage: node add.js <integer1> <integer2>');
  process.exit(1);
}

const num1 = process.argv[2];
const num2 = process.argv[3];

// Parse as integers, handling non-numeric input gracefully
const a = parseInt(num1, 10);
const b = parseInt(num2, 10);

if (isNaN(a) || isNaN(b)) {
  console.error('Error: Both arguments must be valid integers.');
  process.exit(1);
}

console.log(a + b);