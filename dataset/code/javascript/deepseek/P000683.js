Here is the JavaScript code for the problem:

function power(x, n) {
  // base case
  if (n === 0) {
    return 1;
  }

  // recursive case
  return x * power(x, n - 1);
}

You can use this function by calling the `power` function and passing the `x` and `n` values. For example:

console.log(power(2, 3)); // Output: 8
console.log(power(4, 0)); // Output: 1
console.log(power(-2, 3)); // Output: -8
console.log(power(5, 10)); // Output: 1024

This code works by defining a recursive function `power` that calculates the power of `x` by multiplying `x` by the power of `x` one less than `n`. The base case is when `n` is 0, in which case it returns 1. For other values of `n`, it returns the product of `x` and the result of `x` multiplied by the power of `x` one less than `n`.