#!/usr/bin/env node
'use strict';

const args = process.argv.slice(2);

if (args.length !== 2) {
  console.error('Usage: node subtract.js <integer1> <integer2>');
  process.exit(1);
}

const [a, b] = args;

const numA = parseInt(a, 10);
const numB = parseInt(b, 10);

if (isNaN(numA) || isNaN(numB)) {
  console.error('Error: Both arguments must be valid integers.');
  process.exit(1);
}

const result = numA - numB;
console.log(result);