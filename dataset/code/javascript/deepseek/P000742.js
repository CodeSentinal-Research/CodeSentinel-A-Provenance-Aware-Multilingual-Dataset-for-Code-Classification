Here is the JavaScript code for the given problem:

function printNumbers(n) {
  if(n < 1 || n > 10^5) {
    console.log('Invalid input. Please enter a number between 1 and 10^5.');
    return;
  }
  
  console.log(n);
  printNumbers(n - 1);
}

printNumbers(10);

This code uses a recursive function `printNumbers` to print numbers from 1 to `n`. The recursion occurs by calling `printNumbers(n - 1)`, which will print the current number and then call itself with the decremented number.

It is important to note that this solution does not use any iterative constructs (for, while, or do-while). Also, it includes a basic input validation to ensure that the input number is within the specified constraints.