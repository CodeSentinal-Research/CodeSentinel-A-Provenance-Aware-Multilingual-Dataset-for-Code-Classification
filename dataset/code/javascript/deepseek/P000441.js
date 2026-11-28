Here's the JavaScript code:

const input = require('fs').readFileSync('stdin', 'utf8');
const N = Number(input.split('\n')[0]);
const arr = input.split('\n')[1].split(' ').map(Number);

const maxElement = Math.max(...arr);

console.log(maxElement);

In this code, we first read the input from standard input using 'fs' (file system) module's readFileSync method which returns the input as a string. We then split the string into two parts using '\n' as the delimiter. The first part is the number N and the second part is the array elements. We map each element to a Number and then find the maximum element using the Math.max function and spread operator (...). Finally, we log the maximum element to the console.