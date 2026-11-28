Here is a JavaScript function that will toggle the K-th bit of an integer N:

function toggleKthBit(N, K) {
  if (K > 31) {
    throw new Error('K should be between 0 and 31');
  }

  return N ^ (1 << K);
}

This function uses the XOR operator (^) to toggle the K-th bit. The bit at position K is set to 1 if it's 0 and set to 0 if it's 1. The result of the XOR operation is the integer N with the bit at position K toggled.

Please note that this code assumes K is 0-based, which is the common convention in programming. If K is 1-based, the appropriate code would be:

function toggleKthBit(N, K) {
  if (K < 0) {
    throw new Error('K should be greater than or equal to 0');
  }

  return N ^ (1 << K);
}

Also, this code does not check if the K-th bit of the integer N actually exists. In a real-world scenario, you would need to add some checking to ensure K is a valid position in the binary representation of N.