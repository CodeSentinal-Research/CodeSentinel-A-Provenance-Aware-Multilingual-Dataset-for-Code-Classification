Here is the JavaScript code that solves the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the length of the array: ', (n) => {
  rl.question('Enter the number of rotations: ', (k) => {
    const arrayStr = rl.question('Enter the array elements: ');
    const array = arrayStr.split(' ').map(Number);
    const rotatedArray = array.slice(n - k).concat(array.slice(0, n - k));
    console.log(rotatedArray);
    rl.close();
  });
});

This script will first ask for the length of the array and the number of rotations. It will then ask for the elements of the array, which are expected to be space-separated. The script then rotates the array to the right by k positions and prints the result.

Please note, this script uses Node.js's `readline` module to read the input from the console. This allows the script to handle large inputs without being constrained by the console's buffer size.