Here's the JavaScript code to solve the given problem:

// Read input from console
let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let lines = input.split('\n');

// Split input lines into variables
let N = parseInt(lines[0]);
let array = lines[1].split(' ').map(Number);
let [L, R] = [parseInt(lines[2]), parseInt(lines[3])];

// Check constraints
if (!(1 <= L && L <= R && R < N)) {
    console.log('Invalid input');
    process.exit(1);
}

// Compute sum between L and R (inclusive)
let sum = array.slice(L, R + 1).reduce((a, b) => a + b, 0);

// Print result
console.log(sum);

This code reads the input from console, splits it into lines, and handles the input as per the constraints. It then computes the sum between the indices L and R (inclusive) and prints the result.