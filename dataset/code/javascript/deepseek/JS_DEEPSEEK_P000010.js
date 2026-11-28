#!/usr/bin/env node
'use strict';

/**
 * Returns the minimum of two integers.
 * @param {number} a - First integer
 * @param {number} b - Second integer
 * @returns {number} The smaller integer
 * @throws {TypeError} If either argument is not an integer
 */
function findMin(a, b) {
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    throw new TypeError('Both arguments must be integers.');
  }
  return Math.min(a, b);
}

// CLI entry point
if (require.main === module) {
  const [, , aStr, bStr] = process.argv;
  if (aStr === undefined || bStr === undefined) {
    console.error('Usage: node <filename> <integer1> <integer2>');
    process.exit(1);
  }
  const a = Number(aStr);
  const b = Number(bStr);
  try {
    const result = findMin(a, b);
    console.log(result);
  } catch (error) {
    console.error(error.message);
    process.exit(1);
  }
}