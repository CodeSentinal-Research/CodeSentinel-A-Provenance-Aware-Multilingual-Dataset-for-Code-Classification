#!/usr/bin/env node
'use strict';

/**
 * Adds two integers and returns the sum.
 * @param {number} a - The first integer.
 * @param {number} b - The second integer.
 * @returns {number} The sum of a and b.
 * @throws {TypeError} If either argument is not an integer.
 */
function addTwoNumbers(a, b) {
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    throw new TypeError('Both arguments must be integers.');
  }
  return a + b;
}

// Entry point when run from command line.
if (require.main === module) {
  const args = process.argv.slice(2);
  if (args.length !== 2) {
    console.error('Usage: node add_two_numbers.js <integer1> <integer2>');
    process.exit(1);
  }
  const a = Number(args[0]);
  const b = Number(args[1]);
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    console.error('Error: Both arguments must be valid integers.');
    process.exit(1);
  }
  console.log(addTwoNumbers(a, b));
}