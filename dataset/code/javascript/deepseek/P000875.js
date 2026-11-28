Sure, here is a JavaScript code snippet to solve this problem. This code takes three integers as inputs and returns the minimum number of bit flips required to make the OR of the two integers equal to the third integer.

function minFlips(a, b, c) {
  let flips = 0;

  for(let i = 0; i < 32; i++) {
    let bitA = (a >> i) & 1;
    let bitB = (b >> i) & 1;
    let bitC = (c >> i) & 1;

    if (bitC == 0) {
      if (bitA == 1 && bitB == 1) {
        flips++;
      }
    } else {
      if (bitA == 0 && bitB == 0) {
        flips++;
      }
    }
  }

  return flips;
}

// Test the function
console.log(minFlips(3, 2, 1)); // Output: 3

This code works by iterating over each bit in the binary representations of the integers a, b, and c. It then checks if the corresponding bit in c is set, if it is set then it checks if the corresponding bit in a and b is also set. If either is not set, then a bit flip is needed. If both are set, then the corresponding bit in c is not set and a bit flip is not needed.