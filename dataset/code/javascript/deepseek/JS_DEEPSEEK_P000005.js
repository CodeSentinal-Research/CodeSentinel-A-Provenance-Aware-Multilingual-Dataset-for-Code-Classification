#!/usr/bin/env node
'use strict';

const args = process.argv.slice(2);

if (args.length !== 2) {
  console.error('Usage: node find-remainder.js <integer1> <integer2>');
  process.exit(1);
}

const [aStr, bStr] = args;

if (!Number.isInteger(Number(aStr)) || !Number.isInteger(Number(bStr))) {
  console.error('Error: Both arguments must be valid integers.');
  process.exit(1);
}

const a = Number(aStr);
const b = Number(bStr);

if (b === 0) {
  console.error('Error: Division by zero is not allowed.');
  process.exit(1);
}

console.log(a % b);