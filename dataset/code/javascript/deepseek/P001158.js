Here is the JavaScript code for the problem:

process.stdin.resume();
process.stdin.on('data', function(data) {
  var N = parseInt(data);
  if (N < 2 || N > 1000) {
    console.log('Invalid input. Please input a positive integer between 2 and 1000.');
    process.stdin.pause();
  } else {
    console.log(maxProduct(N));
  }
});

function maxProduct(N) {
  if (N === 2) return 1;
  if (N === 3) return 2;
  if (N % 3 === 0) return N / 3 * 2;
  if (N % 3 === 1) return (N - 1) / 3 * 2;
  if (N % 3 === 2) return (N - 2) / 3 * 2;
}

In this code, we are reading the input from the standard input and then checking the conditions. If the number is less than 2 or greater than 1000, we print an error message and pause the process. If the number is valid, we call the `maxProduct` function and print the result.

The `maxProduct` function checks for different cases based on the modulus of N by 3. If N is a multiple of 3, we can split it into 3 to get the maximum product. If N is not a multiple of 3, we can split it into 2 and then add 1.

For example, for N = 6, the function will return 3 * 3. For N = 7, the function will return 7 * 1. This is because splitting 7 into 2 and 3 gives the larger product.