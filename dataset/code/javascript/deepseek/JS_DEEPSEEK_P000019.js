/**
 * Prints the multiplication table of a given number up to 10.
 * @param {number} num - The number for the multiplication table.
 * @returns {string[]} Array of formatted table lines.
 * @throws {TypeError} If `num` is not a valid finite number.
 */
function printMultiplicationTable(num) {
  if (typeof num !== 'number' || !isFinite(num)) {
    throw new TypeError('Expected a valid finite number as input.');
  }

  const table = [];
  for (let i = 1; i <= 10; i++) {
    const product = num * i;
    const line = `${num} x ${i} = ${product}`;
    console.log(line);
    table.push(line);
  }
  return table;
}

// Example usage (uncomment to run):
// printMultiplicationTable(5);