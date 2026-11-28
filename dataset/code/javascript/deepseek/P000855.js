Here's the JavaScript code:

function countLeadingZeros(n) {
  if (n < 0 || n > 2 ** 32 - 1) {
    throw new Error('Invalid input. Input must be a 32-bit unsigned integer between 0 and 2^32 - 1');
  }

  let count = 0;
  while (n > 0) {
    if ((n & 1) == 0) {
      count++;
      n >>= 1;
    } else {
      break;
    }
  }

  return count;
}

This function works by continuously dividing the input number by 2 (using the bitwise right shift operator `>>=`), counting the leading zeros, and stopping once the number becomes 1 (because any number greater than 1 ends with at least one leading zero).

You can call the function like this:

console.log(countLeadingZeros(16));  // Outputs: 2

This will output `2` because the binary representation of `16` (which is `10000`) has `2` leading zeros.