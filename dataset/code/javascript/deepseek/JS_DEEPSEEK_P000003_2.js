#!/usr/bin/env node

const arg1 = process.argv[2];
const arg2 = process.argv[3];

if (arg1 === undefined || arg2 === undefined) {
  console.error('Error: Two integer arguments are required.');
  console.error('Usage: multiply.js <integer1> <integer2>');
  process.exit(1);
}

const num1 = Number(arg1);
const num2 = Number(arg2);

if (!Number.isInteger(num1) || !Number.isInteger(num2)) {
  console.error('Error: Both arguments must be valid integers.');
  process.exit(1);
}

console.log(num1 * num2);