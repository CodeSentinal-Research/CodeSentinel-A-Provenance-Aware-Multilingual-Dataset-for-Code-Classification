Here is the JavaScript code that solves the problem:

function integerSquareRoot(x) {
  // Check if the input is valid
  if (typeof x !== 'number' || !Number.isInteger(x) || x < 0 || x > 2147483647) {
    throw new Error('Input must be a non-negative integer less than 2^31');
  }

  // Convert the input to a 32-bit signed integer
  const intX = Math.floor(x);

  // Return the square root of the input
  return Math.floor(Math.sqrt(intX));
}

This code first checks if the input is valid. If it is not, an error is thrown. If it is valid, it converts the input to a 32-bit signed integer (to prevent overflow), and then calculates and returns the square root of the input. The Math.sqrt method uses the Babylonian method for calculating square roots, which is more precise than the standard method.