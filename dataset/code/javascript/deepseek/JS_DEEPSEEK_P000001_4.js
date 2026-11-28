#!/usr/bin/env node
"use strict";

/**
 * Adds two integers.
 * @param {number} a - The first integer.
 * @param {number} b - The second integer.
 * @returns {number} The sum of a and b.
 * @throws {TypeError} If either argument is not an integer.
 */
function addTwoNumbers(a, b) {
  if (!Number.isInteger(a) || !Number.isInteger(b)) {
    throw new TypeError("Both arguments must be integers.");
  }
  return a + b;
}

// CLI entry point
if (require.main === module) {
  const args = process.argv.slice(2);

  if (args.length < 2) {
    console.error("Usage: node add_two_numbers.js <integer1> <integer2>");
    process.exit(1);
  }

  // Safely parse a string argument to an integer.
  // Returns the number if it's a valid integer, otherwise null.
  const parseSafeInteger = (s) => {
    const n = Number(s);
    return Number.isInteger(n) ? n : null;
  };

  const a = parseSafeInteger(args[0]);
  const b = parseSafeInteger(args[1]);

  if (a === null || b === null) {
    console.error("Error: Both arguments must be valid integers.");
    process.exit(1);
  }

  console.log(addTwoNumbers(a, b));
}