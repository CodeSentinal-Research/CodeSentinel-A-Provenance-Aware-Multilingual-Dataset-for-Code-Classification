Here is the JavaScript code that solves the problem:

let [N, ...arr] = require('fs').readFileSync(0).toString().trim().split(' ');
arr = arr.map(Number);
console.log(Math.max(...arr));

This program reads the input from standard input (file descriptor 0) and splits it into an array of strings. It then maps each string into a number, which allows us to work with the numbers in the array. Finally, it uses the Math.max function with spread operator (`...`) to find the largest number in the array, and prints it.