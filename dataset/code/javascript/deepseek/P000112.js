Here is the JavaScript code for the given problem:

// Read the array size and elements
const [N, ...arr] = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n').map(Number);

let numbers = arr[0].toString().split(' ').map(Number);

// Remove duplicates
numbers = [...new Set(numbers)];

// Sort the array in ascending order
numbers.sort((a, b) => a - b);

// Check if second element exists and print it
if (numbers.length >= 2) {
    console.log(numbers[1]);
} else {
    console.log(-1);
}

This program first reads the array size and elements from stdin. Then it removes duplicates from the array and sorts it in ascending order. Finally, it checks if the array has at least two elements. If it does, it prints the second element, otherwise it prints -1.