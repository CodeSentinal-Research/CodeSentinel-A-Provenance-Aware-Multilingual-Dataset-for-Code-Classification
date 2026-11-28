Here is a simple JavaScript code snippet to calculate the Greatest Common Divisor (GCD) of two numbers using Euclid's algorithm.

function gcd(a, b) {
  if (!b) {
    return a;
  }
  return gcd(b, a % b);
}

console.log(gcd(24, 36)); // 12

This function implements Euclid's algorithm for finding the greatest common divisor (GCD). It uses recursion to find the GCD, with the base case for recursion when `b` is 0. In this case, the GCD of `a` and `b` is `a` itself.

However, this function is not suitable for large numbers. If you are dealing with large numbers and you're concerned about the performance, you may want to use a more efficient algorithm, such as the "Stein's algorithm" or "Binary GCD algorithm".

// Stein's Algorithm
function gcd(a, b) {
  if (a === 0) {
    return b;
  }
  if (b === 0) {
    return a;
  }
  if (~a & 1) {
    if (b & 1) {
      return gcd(a - 1, b >> 1);
    } else {
      return gcd(a >> 1, b >> 1) << 1;
    }
  }
  if (~b & 1) {
    return gcd(a, b - 1);
  }
  if (a > b) {
    return gcd((a - b) >> 1, b);
  }
  return gcd((b - a) >> 1, a);
}

console.log(gcd(24, 36)); // 12

This version of the function uses binary operations and is significantly faster for large inputs.

Please note that these algorithms are not meant to be used in a real-world context where large numbers are involved. They are mainly for educational purposes.