function findLargest(a, b, c) {
  // Validate inputs to ensure they are numbers and not NaN
  if (
    typeof a !== 'number' || Number.isNaN(a) ||
    typeof b !== 'number' || Number.isNaN(b) ||
    typeof c !== 'number' || Number.isNaN(c)
  ) {
    throw new TypeError('All arguments must be valid numbers.');
  }

  // Nested if logic to find the largest number
  if (a >= b) {
    if (a >= c) {
      return a;
    } else {
      return c;
    }
  } else {
    if (b >= c) {
      return b;
    } else {
      return c;
    }
  }
}