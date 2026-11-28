#!/usr/bin/env node
'use strict';

const args = process.argv.slice(2);

if (args.length !== 2) {
  console.error('Usage: node add.js <integer1> <integer2>');
  process.exit(1);
}

const isInteger = (s) => /^-?\d+$/.test(s);

if (!isInteger(args[0]) || !isInteger(args[1])) {
  console.error('Error: Both arguments must be valid integers (e.g., 42, -5).');
  process.exit(1);
}

const num1 = parseInt(args[0], 10);
const num2 = parseInt(args[1], 10);
const sum = num1 + num2;

console.log(sum);