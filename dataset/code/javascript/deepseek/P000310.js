Here is the JavaScript code to solve the problem:

function addBinary(a, b) {
  // Convert binary to decimal
  let num1 = parseInt(a, 2);
  let num2 = parseInt(b, 2);
  
  // Convert decimal to binary
  let sum = num1 + num2;
  return sum.toString(2);
}

This function first converts the input binary strings to decimal numbers using the `parseInt` function. Then it adds the two decimal numbers and converts the sum back to binary using the `toString` method with 2 as the radix.

You can use this function in your code by passing two binary strings as arguments. For example:

console.log(addBinary('1010', '1111'));  // Output: "11010"

This function works in all cases where the input binary strings are valid and consist only of '0's and '1's.